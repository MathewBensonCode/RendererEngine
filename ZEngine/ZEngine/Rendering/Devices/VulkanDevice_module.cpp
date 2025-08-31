module;
#include <vk_mem_alloc.h>
#include <vulkan/vulkan.h>

export module ZEngine.Rendering:Devices.VulkanDevice;

import std;
import :ResourceTypes;
import :Devices.VulkanLayer;
import ZEngine.Helpers.HandleManager;
import ZEngine.Helpers.MemoryOperations;
import ZEngine.Helpers.ThreadSafeQueue;
import ZEngine.Core.Containers.Array;
import ZEngine.Core.Containers.HashMap;
import ZEngine.Core.Containers.Strings;
import ZEngine.Core.Memory.Allocator;
import ZEngine.ZEngineDef;

namespace ZEngine::Rendering::Windows
{
    struct CoreWindow;
}

namespace ZEngine::Rendering::Textures
{
    struct Texture;
    using TextureHandle        = Helpers::Handle<Texture>;
    using TextureHandleManager = Helpers::HandleManager<Texture>;
} // namespace ZEngine::Rendering::Textures

namespace ZEngine::Rendering::Specifications
{
    struct Image2DBufferSpecification;
    struct ShaderSpecificationType;
} // namespace ZEngine::Rendering::Specifications

namespace ZEngine::Rendering::Renderers::RenderPasses
{
    struct RenderPass;
    struct Attachment;
} // namespace ZEngine::Rendering::Renderers::RenderPasses

namespace ZEngine::Rendering::Shaders
{
    struct Shader;
}

namespace ZEngine::Rendering::Pools
{
    struct CommandPool;
}

namespace ZEngine::Rendering::Primitives
{
    struct Fence;
    struct Semaphore;
    struct ImageMemoryBarrier;
} // namespace ZEngine::Rendering::Primitives

namespace ZEngine::Rendering::windows
{
    struct CoreWindow;
}

namespace ZEngine::Rendering::Devices
{
    struct QueueView;
    struct WriteDescriptorSetRequestKey;
    struct WriteDescriptorSetRequest;
    struct CommandBufferManager;
    /*
     * Vertex | Index | Uniform | Storage Buffers
     */
    struct BufferView;
    struct BufferImage;
    struct IGraphicBuffer;
    struct StorageBuffer;
    struct VertexBuffer;
    struct IndexBuffer;
    struct UniformBuffer;
    struct IndirectBuffer;
    struct CommandBuffer;

    struct DirtyResource;

    template <typename T /*, typename = std::enable_if_t<std::is_base_of_v<IGraphicBuffer, T>> */>
    struct IBufferSet
    {
        Core::Containers::Array<T> set = {};

        T&                         operator[](std::uint32_t index)
        {
            ZENGINE_VALIDATE_ASSERT(index < set.size(), "Index out of range");
            return set[index];
        }

        T& At(std::uint32_t index)
        {
            ZENGINE_VALIDATE_ASSERT(index < set.size(), "Index out of range");
            return set[index];
        }

        template <typename K>
        void SetData(std::uint32_t index, std::span<const K> data)
        {
            ZENGINE_VALIDATE_ASSERT(index < set.size(), "Index out of range");

            // if (std::is_same_v<T, IndexBuffer> || std::is_same_v<T, VertexBuffer> || std::is_same_v<T,
            // StorageBuffer>)
            //{
            // }
            T& entry = set[index];
            entry->template SetData<K>(data);
        }

        void Dispose() {}
    };

    using VertexBufferSet         = IBufferSet<VertexBuffer*>;
    using VertexBufferSetHandle   = Helpers::Handle<VertexBufferSet>;

    using StorageBufferSet        = IBufferSet<StorageBuffer*>;
    using StorageBufferSetHandle  = Helpers::Handle<StorageBufferSet>;

    using IndexBufferSet          = IBufferSet<IndexBuffer*>;
    using IndexBufferSetHandle    = Helpers::Handle<IndexBufferSet>;

    using IndirectBufferSet       = IBufferSet<IndirectBuffer*>;
    using IndirectBufferSetHandle = Helpers::Handle<IndirectBufferSet>;

    using UniformBufferSet        = IBufferSet<UniformBuffer*>;
    using UniformBufferSetHandle  = Helpers::Handle<UniformBufferSet>;

    /*
     * GPU Device
     */
    export struct VulkanDevice
    {
        bool                                                                                HasSeperateTransfertQueueFamily    = false;
        const char*                                                                         ApplicationName                    = "Tetragrama";
        const char*                                                                         EngineName                         = "ZEngine";
        std::uint32_t                                                                       SwapchainImageCount                = 3;
        std::uint32_t                                                                       SwapchainImageIndex                = std::numeric_limits<uint8_t>::max();
        std::uint32_t                                                                       CurrentFrameIndex                  = std::numeric_limits<uint8_t>::max();
        std::uint32_t                                                                       PreviousFrameIndex                 = std::numeric_limits<uint8_t>::max();
        std::uint32_t                                                                       SwapchainImageWidth                = std::numeric_limits<std::uint32_t>::max();
        std::uint32_t                                                                       SwapchainImageHeight               = std::numeric_limits<std::uint32_t>::max();
        std::uint32_t                                                                       GraphicFamilyIndex                 = std::numeric_limits<std::uint32_t>::max();
        std::uint32_t                                                                       TransferFamilyIndex                = std::numeric_limits<std::uint32_t>::max();
        std::uint32_t                                                                       EnqueuedCommandbufferIndex         = 0;
        std::uint32_t                                                                       WriteDescriptorSetIndex            = 0;
        VkInstance                                                                          Instance                           = VK_NULL_HANDLE;
        VkSurfaceKHR                                                                        Surface                            = VK_NULL_HANDLE;
        VkSurfaceFormatKHR                                                                  SurfaceFormat                      = {};
        VkPresentModeKHR                                                                    PresentMode                        = {};
        VkPhysicalDeviceProperties                                                          PhysicalDeviceProperties           = {};
        VkDevice                                                                            LogicalDevice                      = VK_NULL_HANDLE;
        VkPhysicalDevice                                                                    PhysicalDevice                     = VK_NULL_HANDLE;
        VkPhysicalDeviceFeatures                                                            PhysicalDeviceFeature              = {};
        VkPhysicalDeviceMemoryProperties                                                    PhysicalDeviceMemoryProperties     = {};
        VkSwapchainKHR                                                                      SwapchainHandle                    = VK_NULL_HANDLE;
        VmaAllocator                                                                        Vma_Allocator                      = nullptr;
        Core::Containers::Array<VkFormat>                                                   DefaultDepthFormats                = {};
        Rendering::Renderers::RenderPasses::Attachment*                                     SwapchainAttachment                = {};
        Core::Containers::Array<VkImageView>                                                SwapchainImageViews                = {};
        Core::Containers::Array<VkFramebuffer>                                              SwapchainFramebuffers              = {};
        Core::Containers::Array<Rendering::Primitives::Semaphore*>                          SwapchainAcquiredSemaphores        = {};
        Core::Containers::Array<Rendering::Primitives::Semaphore*>                          SwapchainRenderCompleteSemaphores  = {};
        Core::Containers::Array<Rendering::Primitives::Fence*>                              SwapchainSignalFences              = {};
        Core::Containers::Array<CommandBuffer*>                                             EnqueuedCommandbuffers             = {};
        Core::Containers::HashMap<const char*, Helpers::Handle<Rendering::Shaders::Shader>> ShaderCaches                       = {};
        std::set<WriteDescriptorSetRequestKey>                                              WriteBindlessDescriptorSetRequests = {};
        Rendering::Textures::TextureHandleManager                                           GlobalTextures                     = {};
        Helpers::ThreadSafeQueue<Rendering::Textures::TextureHandle>                        TextureHandleToUpdates             = {};
        Helpers::ThreadSafeQueue<Rendering::Textures::TextureHandle>                        TextureHandleToDispose             = {};
        Helpers::HandleManager<Rendering::Shaders::Shader>                                  ShaderManager                      = {};
        Helpers::HandleManager<VertexBufferSet>                                             VertexBufferSetManager             = {};
        Helpers::HandleManager<StorageBufferSet>                                            StorageBufferSetManager            = {};
        Helpers::HandleManager<IndirectBufferSet>                                           IndirectBufferSetManager           = {};
        Helpers::HandleManager<IndexBufferSet>                                              IndexBufferSetManager              = {};
        Helpers::HandleManager<UniformBufferSet>                                            UniformBufferSetManager            = {};
        Helpers::HandleManager<DirtyResource>                                               DirtyResources                     = {};
        Helpers::HandleManager<BufferView>                                                  DirtyBuffers                       = {};
        Helpers::HandleManager<BufferImage>                                                 DirtyBufferImages                  = {};
        std::atomic_bool                                                                    RunningDirtyCollector              = true;
        std::atomic_uint                                                                    IdleFrameCount                     = 0;
        std::atomic_uint                                                                    IdleFrameThreshold                 = SwapchainImageCount * 3 * 3;
        std::condition_variable                                                             DirtyCollectorCond                 = {};
        std::mutex                                                                          DirtyMutex                         = {};
        Windows::CoreWindow*                                                                CurrentWindow                      = nullptr;
        ZEngine::Core::Memory::ArenaAllocator*                                              Arena                              = nullptr;

        void                                                                                Initialize(ZEngine::Core::Memory::ArenaAllocator* arena, Windows::CoreWindow* const window);
        void                                                                                Deinitialize();
        void                                                                                Update();
        void                                                                                Dispose();
        bool                                                                                QueueSubmit(const VkPipelineStageFlags wait_stage_flag, CommandBuffer* const command_buffer, Rendering::Primitives::Semaphore* const signal_semaphore = nullptr, Rendering::Primitives::Fence* const fence = nullptr);
        void                                                                                EnqueueForDeletion(Rendering::DeviceResourceType resource_type, void* const resource_handle);
        void                                                                                EnqueueForDeletion(Rendering::DeviceResourceType resource_type, DirtyResource resource);
        void                                                                                EnqueueBufferForDeletion(BufferView& buffer);
        void                                                                                EnqueueBufferImageForDeletion(BufferImage& buffer);
        QueueView                                                                           GetQueue(Rendering::QueueType type);
        void                                                                                QueueWait(Rendering::QueueType type);
        void                                                                                QueueWaitAll();
        void                                                                                MapAndCopyToMemory(BufferView& buffer, size_t data_size, const void* data);
        BufferView                                                                          CreateBuffer(VkDeviceSize byte_size, VkBufferUsageFlags buffer_usage, VmaAllocationCreateFlags vma_create_flags = 0);
        void                                                                                CopyBuffer(const BufferView& source, const BufferView& destination, VkDeviceSize byte_size);
        BufferImage                                                                         CreateImage(std::uint32_t width, std::uint32_t height, VkImageType image_type, VkImageViewType image_view_type, VkFormat image_format, VkImageTiling image_tiling, VkImageLayout image_initial_layout, VkImageUsageFlags image_usage, VkSharingMode image_sharing_mode, VkSampleCountFlagBits image_sample_count, VkMemoryPropertyFlags requested_properties, VkImageAspectFlagBits image_aspect_flag, std::uint32_t layer_count = 1U, VkImageCreateFlags image_create_flag_bit = 0);
        VkSampler                                                                           CreateImageSampler();
        VkFormat                                                                            FindSupportedFormat(Core::Containers::ArrayView<VkFormat> format_collection, VkImageTiling image_tiling, VkFormatFeatureFlags feature_flags);
        VkFormat                                                                            FindDepthFormat();
        VkImageView                                                                         CreateImageView(VkImage image, VkFormat image_format, VkImageViewType image_view_type, VkImageAspectFlagBits image_aspect_flag, std::uint32_t layer_count = 1U);
        VkFramebuffer                                                                       CreateFramebuffer(Core::Containers::ArrayView<VkImageView> attachments, const VkRenderPass& render_pass, std::uint32_t width, std::uint32_t height, std::uint32_t layer_number = 1);
        VertexBufferSetHandle                                                               CreateVertexBufferSet();
        StorageBufferSetHandle                                                              CreateStorageBufferSet();
        IndirectBufferSetHandle                                                             CreateIndirectBufferSet();
        IndexBufferSetHandle                                                                CreateIndexBufferSet();
        UniformBufferSetHandle                                                              CreateUniformBufferSet();
        void                                                                                CreateSwapchain();
        void                                                                                ResizeSwapchain();
        void                                                                                DisposeSwapchain();
        void                                                                                NewFrame();
        void                                                                                Present();
        void                                                                                IncrementFrameImageCount();
        CommandBuffer*                                                                      GetCommandBuffer(bool begin = true);
        CommandBuffer*                                                                      GetInstantCommandBuffer(Rendering::QueueType type, bool begin = true);
        void                                                                                EnqueueInstantCommandBuffer(CommandBuffer* const buffer, int wait_flag = 0);
        void                                                                                EnqueueCommandBuffer(CommandBuffer* const buffer);
        void                                                                                DirtyCollector();

        Helpers::Handle<Rendering::Shaders::Shader>                                         CompileShader(Rendering::Specifications::ShaderSpecificationType& spec);

    private:
        VulkanLayer                                              m_layer          = {};
        CommandBufferManager*                                    m_buffer_manager = {};
        Core::Containers::HashMap<Rendering::QueueType, VkQueue> m_queue_map      = {};
        VkDebugUtilsMessengerEXT                                 m_debug_messenger{VK_NULL_HANDLE};
        PFN_vkCreateDebugUtilsMessengerEXT                       __createDebugMessengerPtr{VK_NULL_HANDLE};
        PFN_vkDestroyDebugUtilsMessengerEXT                      __destroyDebugMessengerPtr{VK_NULL_HANDLE};
        void                                                     __cleanupDirtyResource();
        void                                                     __cleanupBufferDirtyResource();
        void                                                     __cleanupBufferImageDirtyResource();
        static VKAPI_ATTR VkBool32 VKAPI_CALL                    __debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);
    };

    struct BufferView
    {
        uint8_t       FrameIndex = std::numeric_limits<uint8_t>::max();
        VkBuffer      Handle     = VK_NULL_HANDLE;
        VmaAllocation Allocation = nullptr;

                      operator bool() const
        {
            return (Handle != VK_NULL_HANDLE);
        }
    };

    struct BufferImage
    {
        uint8_t       FrameIndex{std::numeric_limits<uint8_t>::max()};
        VkImage       Handle{VK_NULL_HANDLE};
        VkImageView   ViewHandle{VK_NULL_HANDLE};
        VkSampler     Sampler{VK_NULL_HANDLE};
        VmaAllocation Allocation{nullptr};

                      operator bool() const
        {
            return (Handle != VK_NULL_HANDLE);
        }
    };

    struct IGraphicBuffer
    {
        IGraphicBuffer()
        {
            m_last_byte_size = m_byte_size;
        }

        IGraphicBuffer(Devices::VulkanDevice* device) : m_device(device)
        {
            m_last_byte_size = m_byte_size;
        }

        virtual ~IGraphicBuffer() = default;

        virtual size_t GetByteSize() const
        {
            return m_byte_size;
        }

        virtual bool HasBeenResized() const
        {
            return m_last_byte_size != m_byte_size;
        }

        virtual void*          GetNativeBufferHandle() const = 0;

        size_t                 m_byte_size{0};
        size_t                 m_last_byte_size{0};
        Devices::VulkanDevice* m_device{nullptr};
    };

    class VertexBuffer : public IGraphicBuffer
    {
    public:
        explicit VertexBuffer(Devices::VulkanDevice* device) : IGraphicBuffer(device) {}

        void SetData(const void* data, size_t byte_size);

        template <typename T>
        void SetData(std::span<const T> content)
        {
            SetData(content.data(), content.size_bytes());
        }

        ~VertexBuffer()
        {
            CleanUpMemory();
        }

        void* GetNativeBufferHandle() const override
        {
            return reinterpret_cast<void*>(m_vertex_buffer.Handle);
        }

        const VkDescriptorBufferInfo& GetDescriptorBufferInfo()
        {
            m_buffer_info = VkDescriptorBufferInfo{.buffer = m_vertex_buffer.Handle, .offset = 0, .range = this->m_byte_size};
            return m_buffer_info;
        }

        void Dispose()
        {
            CleanUpMemory();
        }

    private:
        void CleanUpMemory();

    private:
        BufferView             m_vertex_buffer;
        VkDescriptorBufferInfo m_buffer_info{};
    };

    template <>
    void VertexBufferSet::Dispose()
    {
        for (auto buffer : set)
        {
            if (buffer)
            {
                buffer->Dispose();
            }
        }
    }

    class StorageBuffer : public IGraphicBuffer
    {
    public:
        explicit StorageBuffer(Devices::VulkanDevice* device) : IGraphicBuffer(device) {}

        void SetData(const void* data, std::uint32_t offset, size_t byte_size);

        template <typename T>
        void SetData(std::span<const T> content)
        {
            SetData(content.data(), 0, content.size_bytes());
        }

        ~StorageBuffer()
        {
            CleanUpMemory();
        }

        void* GetNativeBufferHandle() const
        {
            return reinterpret_cast<void*>(m_storage_buffer.Handle);
        }

        const VkDescriptorBufferInfo& GetDescriptorBufferInfo()
        {
            m_buffer_info = VkDescriptorBufferInfo{.buffer = m_storage_buffer.Handle, .offset = 0, .range = this->m_byte_size};
            return m_buffer_info;
        }

        void Dispose()
        {
            CleanUpMemory();
        }

    private:
        void CleanUpMemory();

    private:
        BufferView             m_storage_buffer;
        VkDescriptorBufferInfo m_buffer_info{};
    };

    template <>
    void StorageBufferSet::Dispose()
    {
        for (auto buffer : set)
        {
            if (buffer)
            {
                buffer->Dispose();
            }
        }
    }

    class IndexBuffer : public IGraphicBuffer
    {
    public:
        IndexBuffer(Devices::VulkanDevice* device) : IGraphicBuffer(device) {}

        void SetData(const void* data, size_t byte_size);

        template <typename T>
        void SetData(std::span<const T> content)
        {
            SetData(content.data(), content.size_bytes());
        }

        ~IndexBuffer()
        {
            CleanUpMemory();
        }

        void* GetNativeBufferHandle() const override
        {
            return reinterpret_cast<void*>(m_index_buffer.Handle);
        }

        const VkDescriptorBufferInfo& GetDescriptorBufferInfo()
        {
            m_buffer_info = VkDescriptorBufferInfo{.buffer = m_index_buffer.Handle, .offset = 0, .range = this->m_byte_size};
            return m_buffer_info;
        }

        void Dispose()
        {
            CleanUpMemory();
        }

    private:
        void CleanUpMemory();

    private:
        BufferView             m_index_buffer;
        VkDescriptorBufferInfo m_buffer_info{};
    };

    template <>
    void IndexBufferSet::Dispose()
    {
        for (auto buffer : set)
        {
            if (buffer)
            {
                buffer->Dispose();
            }
        }
    }

    class IndirectBuffer : public IGraphicBuffer
    {
    public:
        explicit IndirectBuffer(Devices::VulkanDevice* device) : IGraphicBuffer(device) {}

        void SetData(const VkDrawIndirectCommand* data, size_t byte_size);

        template <typename T>
        void SetData(std::span<const T> content)
        {
            SetData(content.data(), content.size_bytes());
        }

        std::uint32_t GetCommandCount() const
        {
            return m_command_count;
        }

        ~IndirectBuffer()
        {
            CleanUpMemory();
        }

        void* GetNativeBufferHandle() const override
        {
            return reinterpret_cast<void*>(m_indirect_buffer.Handle);
        }

        void Dispose()
        {
            CleanUpMemory();
        }

    private:
        void CleanUpMemory();

    private:
        std::uint32_t m_command_count{0};
        BufferView    m_indirect_buffer;
    };

    template <>
    template <>
    void IndirectBufferSet::SetData<VkDrawIndirectCommand>(std::uint32_t index, std::span<const VkDrawIndirectCommand> data)
    {
        ZENGINE_VALIDATE_ASSERT(index < set.size(), "Index out of range");
        set[index]->SetData(data);
    }

    template <>
    void IndirectBufferSet::Dispose()
    {
        for (auto buffer : set)
        {
            if (buffer)
            {
                buffer->Dispose();
            }
        }
    }

    class UniformBuffer : public IGraphicBuffer
    {
    public:
        explicit UniformBuffer() : IGraphicBuffer(nullptr) {}
        explicit UniformBuffer(Devices::VulkanDevice* device) : IGraphicBuffer(device) {}

        explicit UniformBuffer(const UniformBuffer& rhs) = delete;

        explicit UniformBuffer(UniformBuffer& rhs)
        {
            this->m_device    = rhs.m_device;
            this->m_byte_size = rhs.m_byte_size;

            std::swap(this->m_uniform_buffer, rhs.m_uniform_buffer);
            std::swap(this->m_uniform_buffer_mapped, rhs.m_uniform_buffer_mapped);

            rhs.m_byte_size             = 0;
            rhs.m_uniform_buffer_mapped = false;
            rhs.m_uniform_buffer        = {};
        }

        explicit UniformBuffer(UniformBuffer&& rhs) noexcept
        {
            this->m_device    = rhs.m_device;
            this->m_byte_size = rhs.m_byte_size;

            std::swap(this->m_uniform_buffer, rhs.m_uniform_buffer);
            std::swap(this->m_uniform_buffer_mapped, rhs.m_uniform_buffer_mapped);

            rhs.m_byte_size             = 0;
            rhs.m_uniform_buffer_mapped = false;
            rhs.m_uniform_buffer        = {};
        }

        UniformBuffer& operator=(const UniformBuffer& rhs) = delete;

        UniformBuffer& operator=(UniformBuffer& rhs)
        {
            if (this == &rhs)
            {
                return *this;
            }

            this->m_byte_size = rhs.m_byte_size;
            this->m_device    = rhs.m_device;

            std::swap(this->m_uniform_buffer, rhs.m_uniform_buffer);
            std::swap(this->m_uniform_buffer_mapped, rhs.m_uniform_buffer_mapped);

            rhs.m_byte_size             = 0;
            rhs.m_uniform_buffer_mapped = false;
            rhs.m_uniform_buffer        = {};

            return *this;
        }

        UniformBuffer& operator=(UniformBuffer&& rhs) noexcept
        {
            if (this == &rhs)
            {
                return *this;
            }

            this->m_byte_size = rhs.m_byte_size;
            this->m_device    = rhs.m_device;

            std::swap(this->m_uniform_buffer, rhs.m_uniform_buffer);
            std::swap(this->m_uniform_buffer_mapped, rhs.m_uniform_buffer_mapped);

            rhs.m_byte_size             = 0;
            rhs.m_uniform_buffer_mapped = false;
            rhs.m_uniform_buffer        = {};

            return *this;
        }

        void SetData(const void* data, size_t byte_size);

        template <typename T>
        void SetData(Core::Containers::ArrayView<T> content)
        {
            size_t byte_size = sizeof(T) * content.size();
            this->SetData(content.data(), byte_size);
        }

        void* GetNativeBufferHandle() const override
        {
            return reinterpret_cast<void*>(m_uniform_buffer.Handle);
        }

        void Dispose()
        {
            CleanUpMemory();
        }

        ~UniformBuffer()
        {
            CleanUpMemory();
        }

        const VkDescriptorBufferInfo& GetDescriptorBufferInfo()
        {
            m_buffer_info = VkDescriptorBufferInfo{.buffer = m_uniform_buffer.Handle, .offset = 0, .range = m_byte_size};
            return m_buffer_info;
        }

    private:
        void CleanUpMemory();

    private:
        bool                   m_uniform_buffer_mapped{false};
        BufferView             m_uniform_buffer{};
        VkDescriptorBufferInfo m_buffer_info{};
    };

    template <>
    void UniformBufferSet::Dispose()
    {
        for (auto buffer : set)
        {
            if (buffer)
            {
                buffer->Dispose();
            }
        }
    }

    struct Image2DBuffer
    {
        Image2DBuffer(VulkanDevice* device, const Rendering::Specifications::Image2DBufferSpecification& spec);
        ~Image2DBuffer();

        BufferImage&           GetBuffer();
        const BufferImage&     GetBuffer() const;
        VkImageView            GetImageViewHandle() const;
        VkImage                GetHandle() const;
        VkSampler              GetSampler() const;
        void                   Dispose();
        VkDescriptorImageInfo& GetDescriptorImageInfo();

    private:
        std::uint32_t         m_width{1};
        std::uint32_t         m_height{1};
        BufferImage           m_buffer_image;
        VkDescriptorImageInfo m_image_info;
        VulkanDevice*         m_device{nullptr};
    };

    struct DirtyResource
    {
        std::uint32_t                 FrameIndex = UINT32_MAX;
        void*                         Handle     = nullptr;
        void*                         Data1      = nullptr;
        Rendering::DeviceResourceType Type;
    };

    struct QueueView
    {
        std::uint32_t FamilyIndex{0xFFFFFFFF};
        VkQueue       Handle{VK_NULL_HANDLE};
    };

    /*
     * Command Buffer definition
     */
    enum CommanBufferState : uint8_t
    {
        Idle = 0,
        Recording,
        Executable,
        Pending,
        Invalid
    };

    struct CommandBuffer
    {
        CommandBuffer(Devices::VulkanDevice* device, VkCommandPool command_pool, Rendering::QueueType type, bool one_time);
        ~CommandBuffer();

        Rendering::QueueType              QueueType;
        Devices::VulkanDevice*            Device     = nullptr;
        Core::Memory::ArenaAllocator      LocalArena = {};

        void                              Create();
        void                              Free();
        VkCommandBuffer                   GetHandle() const;
        void                              Begin();
        void                              End();
        bool                              Completed();
        bool                              IsExecutable();
        bool                              IsRecording();
        CommanBufferState                 GetState() const;
        void                              ResetState();
        void                              SetState(const CommanBufferState& state);
        void                              SetSignalFence(Rendering::Primitives::Fence* const semaphore);
        void                              SetSignalSemaphore(Rendering::Primitives::Semaphore* const semaphore);
        Rendering::Primitives::Semaphore* GetSignalSemaphore() const;
        Rendering::Primitives::Fence*     GetSignalFence();
        void                              ClearColor(float r, float g, float b, float a);
        void                              ClearDepth(float depth_color, std::uint32_t stencil);
        void                              BeginRenderPass(Rendering::Renderers::RenderPasses::RenderPass* const, VkFramebuffer framebuffer);
        void                              EndRenderPass();
        void                              BindDescriptorSets(std::uint32_t frame_index = 0);
        void                              BindDescriptorSet(const VkDescriptorSet& descriptor);
        void                              DrawIndirect(const Devices::IndirectBuffer& buffer);
        void                              DrawIndexedIndirect(const Devices::IndirectBuffer& buffer, std::uint32_t count);
        void                              DrawIndexed(std::uint32_t indexCount, std::uint32_t instanceCount, std::uint32_t firstIndex, int32_t vertexOffset, std::uint32_t firstInstance);
        void                              Draw(std::uint32_t vertex_count, std::uint32_t instance_count, std::uint32_t first_index, std::uint32_t first_instance);
        void                              TransitionImageLayout(const Rendering::Primitives::ImageMemoryBarrier& image_barrier);
        void                              CopyBufferToImage(const Devices::BufferView& source, Devices::BufferImage& destination, std::uint32_t width, std::uint32_t height, std::uint32_t layer_count, VkImageLayout new_layout);
        void                              BindVertexBuffer(Devices::VertexBuffer& buffer);
        void                              BindIndexBuffer(const Devices::IndexBuffer& buffer, VkIndexType type);
        void                              SetScissor(const VkRect2D& scissor);
        void                              PushConstants(VkShaderStageFlags stage_flags, std::uint32_t offset, std::uint32_t size, const void* data);

    private:
        std::atomic_uint8_t                             m_command_buffer_state{CommanBufferState::Idle};
        VkCommandBuffer                                 m_command_buffer{VK_NULL_HANDLE};
        VkCommandPool                                   m_command_pool{VK_NULL_HANDLE};
        VkClearValue                                    m_clear_value[2] = {0};
        Rendering::Primitives::Fence*                   m_signal_fence;
        Rendering::Primitives::Semaphore*               m_signal_semaphore;
        Rendering::Renderers::RenderPasses::RenderPass* m_active_render_pass;
    };

    struct CommandBufferManager
    {
        void                                                    Initialize(VulkanDevice* device, uint8_t swapchain_image_count = 3, int thread_count = 1);
        void                                                    Deinitialize();
        CommandBuffer*                                          GetCommandBuffer(uint8_t frame_index, bool begin = true);
        CommandBuffer*                                          GetInstantCommandBuffer(Rendering::QueueType type, uint8_t frame_index, bool begin = true);
        void                                                    EndInstantCommandBuffer(CommandBuffer* const buffer, VulkanDevice* const device, int wait_flag = 0);
        Rendering::Pools::CommandPool*                          GetCommandPool(Rendering::QueueType type, uint8_t frame_index);
        int                                                     GetPoolFromIndex(Rendering::QueueType type, uint8_t index);
        void                                                    ResetPool(int frame_index);

        VulkanDevice*                                           Device                  = nullptr;
        const int                                               MaxBufferPerPool        = 4;
        Core::Containers::Array<Rendering::Pools::CommandPool*> CommandPools            = {};
        Core::Containers::Array<Rendering::Pools::CommandPool*> TransferCommandPools    = {};
        Core::Containers::Array<CommandBuffer*>                 CommandBuffers          = {};
        Core::Containers::Array<CommandBuffer*>                 TransferCommandBuffers  = {};
        int                                                     TotalCommandBufferCount = 0;

    private:
        int                               m_total_pool_count{0};
        std::condition_variable           m_cond;
        std::atomic_bool                  m_executing_instant_command{false};
        std::mutex                        m_instant_command_mutex;
        Rendering::Primitives::Semaphore* m_instant_semaphore;
        Rendering::Primitives::Fence*     m_instant_fence;
    };

    struct WriteDescriptorSetRequestKey
    {
        std::uint32_t   Binding = 0;
        VkDescriptorSet DstSet  = VK_NULL_HANDLE;

        bool            operator<(const WriteDescriptorSetRequestKey& other) const
        {
            if (Binding != other.Binding)
                return Binding < other.Binding;
            return DstSet < other.DstSet;
        }
    };

    struct WriteDescriptorSetRequest
    {
        bool             Updated = false;
        int              Handle;
        std::uint32_t    FrameIndex;
        VkDescriptorSet  DstSet;
        std::uint32_t    Binding;
        std::uint32_t    DstArrayElement;
        std::uint32_t    DescriptorCount;
        VkDescriptorType DescriptorType;
    };

    /*
     *  Device definition
     */
} // namespace ZEngine::Rendering::Devices
