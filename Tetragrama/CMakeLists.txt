cmake_minimum_required (VERSION 3.17)

project (Tetragrama 
	VERSION 1.0
	DESCRIPTION "Tetragrama, the ZEngine Editor"
	LANGUAGES CXX
)

set (CMAKE_CXX_STANDARD_REQUIRED ON)
set	(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_EXTENSIONS OFF)

file (GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)
file (GLOB_RECURSE CPP_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

source_group (TREE ${PROJECT_SOURCE_DIR}/src PREFIX "Header Files" FILES ${HEADER_FILES})
source_group (TREE ${PROJECT_SOURCE_DIR}/src PREFIX "Source Files" FILES ${CPP_FILES})

set (TARGET_NAME tetragrama)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    add_executable (Tetragrama WIN32)
else()
    add_executable (Tetragrama)
endif()

target_sources(Tetragrama PUBLIC ${HEADER_FILES} ${CPP_FILES})

# We set this debugger directory to find assets and resources file
# after being copied to Debug and Release output directories 
#
if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set_target_properties(Tetragrama PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "$(ProjectDir)$(Configuration)")
endif ()

target_include_directories (Tetragrama
	PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Components
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Layers
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Messengers
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Helpers
)

#target_precompile_headers(Tetragrama PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/pch.h)

#target_compile_definitions (Tetragrama
#	PRIVATE
#		IMGUI_IMPL_OPENGL_LOADER_GLAD
#)

target_link_libraries(Tetragrama
    PRIVATE
        zEngineLib
)

set_target_properties(Tetragrama PROPERTIES OUTPUT_NAME "zEngineEditor")
