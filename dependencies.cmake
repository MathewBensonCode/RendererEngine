include(FetchContent)

Fetchcontent_Declare(
    tlsf
    GIT_REPOSITORY https://github.com/mattconte/tlsf
    GIT_SHALLOW TRUE
    SOURCE_DIR ${FETCHCONTENT_BASE_DIR}/tlsf
)

Fetchcontent_MakeAvailable(
    tlsf
)

find_package(fmt CONFIG REQUIRED)
find_package(VulkanHeaders CONFIG REQUIRED)
find_package(VulkanLoader CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(imGuizmo CONFIG REQUIRED)
find_package(Stb MODULE REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(assimp CONFIG REQUIRED)
find_package(stduuid CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)
find_package(VulkanMemoryAllocator CONFIG REQUIRED)
find_package(SPIRV-Headers CONFIG REQUIRED)
find_package(spirv_cross_core CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)
find_package(SPIRV-Tools CONFIG REQUIRED)
find_package(glslang CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_path(RAPIDHASH_INCLUDE_DIRS "rapidhash.h")

add_library(External_libs INTERFACE EXCLUDE_FROM_ALL)
target_include_directories(External_libs INTERFACE ${RAPIDHASH_INCLUDE_DIRS})

target_link_libraries(External_libs
    INTERFACE
         Vulkan
         glfw
         fmt::fmt
         imgui::imgui
         imguizmo::imguizmo
         spdlog::spdlog_header_only
         EnTT::EnTT
         assimp::assimp
         stduuid
         yaml-cpp::yaml-cpp
         spirv-cross-core
         glslang::SPIRV
         nlohmann_json::nlohmann_json
         tlsf
)


add_library(imported::ZEngine_External_Dependencies ALIAS External_libs)

add_library(External_obeliskLibs INTERFACE)
target_link_libraries(External_obeliskLibs 
    INTERFACE 
    CLI11::CLI11
)
add_library(imported::External_obeliskLibs ALIAS External_obeliskLibs)

include(${CMAKE_CURRENT_SOURCE_DIR}/Scripts/CMake/NuGet.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/Scripts/CMake/CppWinRT.cmake)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    # Install necessary NuGet dependencies
    install_nuget_package(Microsoft.Windows.CppWinRT 2.0.240405.15 CPPWINRT_NUGET_PATH)

    # Generate CppWinRT headers for the local OS
    generate_winrt_headers(
        EXECUTABLE
            ${CPPWINRT_NUGET_PATH}/bin/cppwinrt.exe
        INPUT
            local
        OUTPUT
            ${CMAKE_BINARY_DIR}/__winrt
        OPTIMIZE
    )

    add_library(imported::cppwinrt_headers INTERFACE)
    target_include_directories(imported::cppwinrt_headers INTERFACE
        ${CMAKE_BINARY_DIR}/__winrt
    )
endif()
