cmake_minimum_required (VERSION 3.17)

project (Tetragrama 
	VERSION 1.0
	DESCRIPTION "Tetragrama, the ZEngine Editor"
	LANGUAGES CXX
)

add_executable (Tetragrama)

target_sources(Tetragrama PUBLIC 
    src/EntryPoint.cpp
    src/Editor.cpp
    src/Importers/AssetImporter.cpp
    src/Importers/AssimpImporter.cpp
    src/EditorCameraController.cpp
    src/Helpers/WindowsHelper.cpp
    src/Helpers/UIComponentDrawerHelper.cpp
    src/Serializers/EditorSceneSerializer.cpp
    src/Components/SceneViewportUIComponent.cpp
    src/Components/HierarchyViewUIComponent.cpp
    src/Components/DockspaceUIComponent.cpp
    src/Components/InspectorViewUIComponent.cpp
    src/Components/LogUIComponent.cpp
    src/Components/ProjectViewUIComponent.cpp
    src/Layers/RenderLayer.cpp
    src/Layers/UILayer.cpp
)

# We set this debugger directory to find assets and resources file
# after being copied to Debug and Release output directories 
#
if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set_target_properties(Tetragrama PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "$(ProjectDir)$(Configuration)")
endif ()

target_include_directories (Tetragrama
	PRIVATE
        include/
        include/Components/
        # include/Layers/
        # include/Messengers/
        # include/Helpers/
        # include/Importers/
        # include/Serializers/
)

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
