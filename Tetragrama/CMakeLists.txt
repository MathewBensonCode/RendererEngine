cmake_minimum_required (VERSION 3.17)

project (Tetragrama 
	VERSION 1.0
	DESCRIPTION "Tetragrama, the ZEngine Editor"
	LANGUAGES CXX
)

add_executable (Tetragrama)

target_include_directories (Tetragrama
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_sources(Tetragrama PRIVATE 
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
