export module ZEngine.Rendering:Devices.CommandBufferManager;

import std;
import :ResourceTypes;
import ZEngine.Core.Containers.Array;

namespace ZEngine::Rendering::Primitives{
    struct Fence;
    struct Semaphore;
}

namespace ZEngine::Rendering::Pools{
    struct CommandPool;
}

namespace ZEngine::Rendering::Devices{

    struct WriteDescriptorSetRequestKey;
    struct WriteDescriptorSetRequest;
    struct CommandBuffer;
    struct CommandBufferManager;
    struct BufferView;
    struct BufferImage;
    struct IGraphicBuffer;
    class StorageBuffer;
    class VertexBuffer;
    class IndexBuffer;
    class UniformBuffer;
    struct VulkanDevice;

    struct CommandBufferManager
    {
        void                                                            Initialize(VulkanDevice* device, std::uint8_t swapchain_image_count = 3, int thread_count = 1);
        void                                                            Deinitialize();
        CommandBuffer*                                                  GetCommandBuffer(std::uint8_t frame_index, bool begin = true);
        CommandBuffer*                                                  GetInstantCommandBuffer(Rendering::QueueType type, uint8_t frame_index, bool begin = true);
        void                                                            EndInstantCommandBuffer(CommandBuffer* const buffer, VulkanDevice* const device, int wait_flag = 0);
        Rendering::Pools::CommandPool*                                  GetCommandPool(Rendering::QueueType type, uint8_t frame_index);
        int                                                             GetPoolFromIndex(Rendering::QueueType type, uint8_t index);
        void                                                            ResetPool(int frame_index);

        VulkanDevice*                                                   Device                  = nullptr;
        const int                                                       MaxBufferPerPool        = 4;
        Core::Containers::Array<Rendering::Pools::CommandPool*> CommandPools            = {};
        Core::Containers::Array<Rendering::Pools::CommandPool*> TransferCommandPools    = {};
        Core::Containers::Array<CommandBuffer*>                 CommandBuffers          = {};
        Core::Containers::Array<CommandBuffer*>                 TransferCommandBuffers  = {};
        int                                                             TotalCommandBufferCount = 0;

    private:
        int                     m_total_pool_count{0};
        std::condition_variable m_cond;
        std::atomic_bool        m_executing_instant_command{false};
        std::mutex              m_instant_command_mutex;
        Rendering::Primitives::Semaphore* m_instant_semaphore;
        Rendering::Primitives::Fence* m_instant_fence;
    };
}
