cmake_minimum_required (VERSION 3.17)

project (Tetragrama 
	VERSION 1.0
	DESCRIPTION "Tetragrama, the ZEngine Editor"
	LANGUAGES CXX
)

file (GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file (GLOB_RECURSE CPP_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

source_group (TREE ${PROJECT_SOURCE_DIR} PREFIX "Source Files" FILES ${HEADER_FILES} ${CPP_FILES})

set (TARGET_NAME tetragrama)

add_library (tetragrama)

target_sources(tetragrama PUBLIC ${HEADER_FILES} ${CPP_FILES})

# We set this debugger directory to find assets and resources file
# after being copied to Debug and Release output directories 
#
if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set_target_properties(tetragrama PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "$(ProjectDir)$(Configuration)")
endif ()

target_include_directories (tetragrama
    PUBLIC
        .
        ./Components
        ./Components/Events
        ./Controllers
        ./Inputs
        ./Layers
        ./Messengers
        ./Helpers
        ./Importers
        ./Serializers
        ./Managers
)

target_compile_definitions(tetragrama
    PRIVATE
        NOMINMAX
        UNICODE
        _UNICODE
)

target_link_libraries(tetragrama PUBLIC zEngineLib)
