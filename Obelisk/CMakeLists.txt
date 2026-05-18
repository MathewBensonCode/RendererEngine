cmake_minimum_required (VERSION 3.17)

project (Obelisk 
	VERSION 1.0
	DESCRIPTION "Obelisk, The game application entry point"
	LANGUAGES CXX
)


if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    add_executable (Obelisk WIN32)
else()
    add_executable (Obelisk)
endif()

target_sources(Obelisk PUBLIC EntryPoint.cpp)

# We set this debugger directory to find assets and resources file
# after being copied to Debug and Release output directories 
#
if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set_target_properties(Obelisk PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "$(ProjectDir)$(Configuration)")
endif ()

target_include_directories (Obelisk
    PRIVATE
        .
        ${ENLISTMENT_ROOT}
        ${ENLISTMENT_ROOT}/ZEngine
)

target_compile_definitions(Obelisk
    PRIVATE
        NOMINMAX
        UNICODE
        _UNICODE
)

target_link_libraries(Obelisk PUBLIC
    tetragrama
    imported::External_obeliskLibs
)

install(TARGETS Obelisk DESTINATION bin)
