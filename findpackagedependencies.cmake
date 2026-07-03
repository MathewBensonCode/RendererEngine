find_package(VulkanHeaders CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(VulkanLoader CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(fmt CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(imgui CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(imguizmo CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(stb CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(glfw3 CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(spdlog CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(EnTT CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(assimp CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(stduuid CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(yaml-cpp CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(VulkanMemoryAllocator CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(SPIRV-Headers CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(spirv_cross_core CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(nlohmann_json CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(tlsf CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(CLI11 CONFIG REQUIRED)
find_package(rapidhash CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(SPIRV-Tools CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(glslang CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
find_package(GTest CONFIG REQUIRED NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)

add_library(External_libs INTERFACE)

target_link_libraries(External_libs
    INTERFACE
         Vulkan::Headers
         Vulkan::Loader
         glfw
         fmt::fmt
         imguizmo
         spdlog::spdlog
         EnTT::EnTT
         assimp::assimp
         stduuid
         yaml-cpp::yaml-cpp
         spirv-cross-core
         SPIRV-Tools-opt
         glslang::glslang
         glslang::glslang-default-resource-limits
         glslang::SPIRV
         GPUOpen::VulkanMemoryAllocator 
         nlohmann_json::nlohmann_json
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

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
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

    add_library(imported::cppwinrt_headers INTERFACE IMPORTED)
    target_include_directories(imported::cppwinrt_headers INTERFACE
        ${CMAKE_BINARY_DIR}/__winrt
    )
endif()
