export module ZEngine.Rendering:Devices.VulkanBufferHandles;

import ZEngine.Helpers.HandleManager;

namespace ZEngine::Rendering::Devices{

    struct StorageBufferSet;
    struct IndexBufferSet;
    struct IndirectBufferSet;
    struct VertexBufferSet;
    struct UniformBufferSet;

    export{
    using StorageBufferSetHandle = Helpers::Handle<StorageBufferSet>;
    using IndexBufferSetHandle = Helpers::Handle<IndexBufferSet>;
    using IndirectBufferSetHandle = Helpers::Handle<IndirectBufferSet>;
    using VertexBufferSetHandle = Helpers::Handle<VertexBufferSet>;
    using UniformBufferSetHandle = Helpers::Handle<UniformBufferSet>;

    VertexBufferSetHandle                                                               CreateVertexBufferSet();
    StorageBufferSetHandle                                                              CreateStorageBufferSet();
    IndirectBufferSetHandle                                                             CreateIndirectBufferSet();
    IndexBufferSetHandle                                                                CreateIndexBufferSet();
    UniformBufferSetHandle                                                              CreateUniformBufferSet();

    }
}
