export module Tetragrama.Editor;

import Tetragrama.Controllers;
import Tetragrama.EditorScene;
import Tetragrama.Helpers;
import Tetragrama.Layers;
import Tetragrama.Serializers;
import ZEngine;

namespace Tetragrama
{

    struct EditorConfiguration
    {
        ZEngine::Core::Containers::String WorkingSpacePath         = {};
        ZEngine::Core::Containers::String DefaultImportTexturePath = {};
        ZEngine::Core::Containers::String DefaultImportSoundPath   = {};
        ZEngine::Core::Containers::String ScenePath                = {};
        ZEngine::Core::Containers::String SceneDataPath            = {};
        ZEngine::Core::Containers::String ProjectName              = {};
        ZEngine::Core::Containers::String ActiveSceneName          = {};

        void                              ReadConfig(ZEngine::Core::Memory::ArenaAllocator* arena, const char* file);
    };

    struct EditorContext
    {
        ZEngine::Core::Memory::ArenaAllocator* Arena                                                                           = nullptr;
        std::atomic_int                        SelectedSceneNode                                                               = -1;
        ZRawPtr(EditorConfiguration) ConfigurationPtr                                                                          = nullptr;
        ZRawPtr(EditorScene) CurrentScenePtr                                                                                   = nullptr;
        ZRawPtr(Controllers::EditorCameraController) CameraControllerPtr                                                       = nullptr;
        ZRawPtr(Managers::AssetManager) AssetManagerPtr                                                                        = nullptr;
        ZEngine::Helpers::Ref<ZEngine::Helpers::ThreadSafeQueue<Managers::AssetManager::AssetHandle>> PendingOnLoadHierarchies = nullptr;
    };

    struct Editor
    {
        ~Editor() {}

        ZRawPtr(EditorContext) Context               = nullptr;
        ZRawPtr(Layers::ImguiLayer) UILayer          = nullptr;
        ZRawPtr(Layers::RenderLayer) CanvasLayer     = nullptr;
        ZRawPtr(ZEngine::Windows::CoreWindow) Window = nullptr;

        void Initialize(ZEngine::Core::Memory::ArenaAllocator*, const char*);
        void Dispose();
        void Run();
    };

} // namespace Tetragrama
