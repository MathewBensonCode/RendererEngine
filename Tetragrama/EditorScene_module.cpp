module;
#include <glm/glm.hpp>
#include <uuid.h>

export module Tetragrama.EditorScene;

import Tetragrama.Importers;
import Tetragrama.Serializers;
import ZEngine;

namespace Tetragrama
{
    struct EditorAssetSceneFiles
    {
        Importers::AssetFileType          Type     = Importers::AssetFileType::UNKNOWN;
        uint64_t                          Hash     = {};
        ZEngine::Core::Containers::String Path     = {};
        ZEngine::Core::Containers::String RootPath = {};
    };

    struct EditorSceneNodeHierarchy : public Helpers::NodeHierarchy
    {
        /*
         * NodeRef serves as a mapping between Scene NodeHierarchy & Asset NodeHierarchy
         */
        Importers::AssetNodeRef NodeRef = {};
    };

    struct EditorScene
    {
        void                                                                Initialize(ZEngine::Core::Memory::ArenaAllocator* arena, const char* scene_name = "");

        bool                                                                HasPendingChange() const;

        std::atomic_bool                                                    Dirty             = false;
        std::atomic_bool                                                    HasPendingChanges = false;

        const char*                                                         Name              = "";
        ZEngine::Core::Containers::Array<EditorSceneNodeHierarchy>          Hierarchies       = {};
        ZEngine::Core::Containers::Array<ZEngine::Core::Containers::String> Names             = {};
        ZEngine::Core::Containers::Array<glm::mat4>                         LocalTransforms   = {};
        ZEngine::Core::Containers::Array<glm::mat4>                         GlobalTransforms  = {};
        ZEngine::Core::Containers::HashMap<uint32_t, uuids::uuid>           NodeMeshes        = {};
        ZEngine::Core::Containers::HashMap<uint32_t, uint32_t>              NodeNames         = {};

        ZEngine::Core::Containers::Array<float>                             Vertices          = {};
        ZEngine::Core::Containers::Array<uint32_t>                          Indices           = {};

        ZEngine::Core::Containers::HashMap<uint64_t, uint32_t>              HashToAssetFile   = {};
        ZEngine::Core::Containers::Array<EditorAssetSceneFiles>             AssetFiles        = {};

        ZEngine::Core::Memory::ArenaAllocator                               LocalArena        = {};

        int                                                                 AddHierarchyNode(int parent, int depth);

        int                                                                 CreateSceneNode(int parent = 0, int depth = 1, const Importers::AssetNodeRef& = {});
        void                                                                RemoveSceneNode(int node_id);
        void                                                                ReparentNode(int node_id, int new_parent);
        bool                                                                IsSceneNodeDeleted(int node_id);

        void                                                                PushAssetFile(const Importers::AssetImporterOutput&);

        void                                                                MarkDirty(bool value);
        bool                                                                IsDirty();

        void                                                                Reset();
        void                                                                InitRootNode();

        void                                                                ExtractAsync(EditorScene& scene); // Todo : this should be const EditorScene& ... the map::view() props
                                                                                                              // prevents us to do it... def a impl issue

        ZRawPtr(ZEngine::Rendering::Scenes::GraphicScene) RenderScene = nullptr;
    };

} // namespace Tetragrama
