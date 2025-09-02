cmake_minimum_required (VERSION 3.17)

project (Tetragrama 
	VERSION 1.0
	DESCRIPTION "Tetragrama, the ZEngine Editor"
	LANGUAGES CXX
)

add_executable (Tetragrama)

target_sources(Tetragrama 
    PUBLIC
    FILE_SET tetragrama_modules
    TYPE CXX_MODULES
    FILES
    Controllers/IController_module.cpp
    Controllers/EditorCameraController_module.cpp
    Controllers/ICameraController_module.cpp
    Controllers/CameraControllerTypeEnums_module.cpp
    Controllers/PerspectiveCameraController_module.cpp
    Controllers/Controllers_module.cpp
    Importers/AssimpImporter_module.cpp
    Importers/AssetTypes_module.cpp
    Importers/IAssetImporter_module.cpp
    Importers/Importers_module.cpp
    EditorScene_module.cpp
    Helpers/Helpers_module.cpp
    Helpers/NodeHierarchyHelper_module.cpp
    Helpers/SearchPatternAlgorithm_module.cpp
    Helpers/UIComponentDrawerHelper_module.cpp
    Helpers/SerializerCommonHelper_module.cpp
    Helpers/UIDispatcher_module.cpp
    Managers/Managers_module.cpp
    Managers/AssetManager_module.cpp
    Messengers/Messengers_module.cpp
    Messengers/Message_module.cpp
    Messengers/Messenger_module.cpp
    EditorWindow_module.cpp
    Serializers/Serializer_module.cpp
    Serializers/EditorSceneSerializer_module.cpp
    Editor_module.cpp
    Components/Components_module.cpp
    Components/HierarchyViewUIComponent_module.cpp
    Components/InspectorViewUIComponent_module.cpp
    Components/LogUIComponent_module.cpp
    Components/DockspaceUIComponent_module.cpp
    Components/SceneViewportUIComponent_module.cpp
    Components/AboutUIComponent_module.cpp
    Components/ProjectViewUIComponent_module.cpp
    Components/UIComponent_module.cpp
    Components/DemoUIComponent_module.cpp
    Components/Events/SceneViewportUnfocusedEvent_module.cpp
    Components/Events/UIComponentEvent_module.cpp
    Components/Events/SceneTextureAvailableEvent_module.cpp
    Components/Events/SceneViewportResizedEvent_module.cpp
    Components/Events/SceneViewportFocusedEvent_module.cpp
    Layers/Layers_module.cpp
    Layers/RenderLayer_module.cpp
    Layers/ImguiLayer_module.cpp
    Inputs/Inputs_module.cpp
    Inputs/Keyboard_module.cpp
    Inputs/Mouse_module.cpp
    MessageToken_module.cpp

    PRIVATE 
    Controllers/EditorCameraController.cpp
    Controllers/PerspectiveCameraController.cpp
    EntryPoint.cpp
    Editor.cpp
    Importers/AssimpImporter.cpp
    Importers/IAssetImporter.cpp
    Helpers/SerializerCommonHelper.cpp
    Helpers/SearchPatternAlgorithm.cpp
    Helpers/UIComponentDrawerHelper.cpp
    Managers/AssetManager.cpp
    Serializers/EditorSceneSerializer.cpp
    EditorScene.cpp
    EditorWindow.cpp
    Components/SceneViewportUIComponent.cpp
    Components/HierarchyViewUIComponent.cpp
    Components/DockspaceUIComponent.cpp
    Components/InspectorViewUIComponent.cpp
    Components/LogUIComponent.cpp
    Components/ProjectViewUIComponent.cpp
    Layers/RenderLayer.cpp
    Layers/ImguiLayer.cpp
)

# We set this debugger directory to find assets and resources file
# after being copied to Debug and Release output directories 
#
if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set_target_properties(Tetragrama PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "$(ProjectDir)$(Configuration)")
endif ()


target_compile_definitions(Tetragrama
    PRIVATE
        NOMINMAX
        UNICODE
        _UNICODE
)

target_link_libraries(Tetragrama
    PRIVATE
    zEngineLib
    nlohmann_json::nlohmann_json
)

set_target_properties(Tetragrama PROPERTIES OUTPUT_NAME "zEngineEditor")
