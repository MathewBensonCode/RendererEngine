cmake_minimum_required(VERSION 3.17)

project(
  ZEngine
  VERSION 1.0
  DESCRIPTION
    "ZEngine is the core engine lib that provides abstraction on top of OpenGL/DirectX/Metal"
  LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(tests)

# Externals dependencies
#
include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  FIND_PACKAGE_ARGS NAMES fmt)

FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui.git
  GIT_SHALLOW TRUE
  GIT_TAG v1.89.9-docking)

FetchContent_Declare(
  stbimage
  GIT_REPOSITORY https://github.com/nothings/stb.git
  GIT_SHALLOW TRUE)

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  FIND_PACKAGE_ARGS NAMES glfw3)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  FIND_PACKAGE_ARGS NAMES spdlog)

FetchContent_Declare(
  glm GIT_REPOSITORY https://github.com/g-truc/glm.git # FIND_PACKAGE_ARGS NAMES
                                                       # glm
)

FetchContent_Declare(entt GIT_REPOSITRY https://github.com/skypjack/entt.git
                          FIND_PACKAGE_ARGS NAMES EnTT)

FetchContent_Declare(
  assimp
  GIT_REPOSITORY https://github.com/assimp/assimp.git
  GIT_TAG v5.3.0
  GIT_SHALLOW TRUE
  FIND_PACKAGE_ARGS NAMES assimp REQUIRED
)

FetchContent_Declare(
  stduuid
  GIT_REPOSITORY https://github.com/mariusbancila/stduuid.git
  FIND_PACKAGE_ARGS NAMES stduuid)

FetchContent_Declare(
  yaml-cpp
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp
  FIND_PACKAGE_ARGS NAMES yaml-cpp)

FetchContent_Declare(
  ImGuizmo
  GIT_REPOSITORY https://github.com/CedricGuillemet/ImGuizmo.git
  GIT_SHALLOW TRUE)

FetchContent_Declare(
  spirv
  GIT_REPOSITORY https://github.com/KhronosGroup/SPIRV-Cross
  GIT_TAG vulkan-sdk-1.3.268.0
  FIND_PACKAGE_ARGS NAMES spirv_cross_core REQUIRED)

FetchContent_Declare(
  VulkanMemoryAllocator
  GIT_REPOSITORY
    https://github.com/GPUOpen-LibrariesAndSDKs/VulkanMemoryAllocator
  GIT_TAG 5e43c795daf43dd09398d8307212e85025215052
  GIT_SHALLOW TRUE)

FetchContent_MakeAvailable(
  fmt
  imgui
  stbimage
  glfw
  spdlog
  glm
  entt
  assimp
  stduuid
  yaml-cpp
  ImGuizmo
  spirv
  VulkanMemoryAllocator)

find_package(Vulkan REQUIRED)

# ZEngine source files
#

set(IMGUIDIR ${FETCHCONTENT_BASE_DIR}/imgui-src)

add_library(imgui STATIC)

target_sources(
  imgui
  PRIVATE ${IMGUIDIR}/imgui.cpp
          ${IMGUIDIR}/imgui_demo.cpp
          ${IMGUIDIR}/imgui_draw.cpp
          ${IMGUIDIR}/imgui_tables.cpp
          ${IMGUIDIR}/imgui_widgets.cpp
          ${IMGUIDIR}/misc/cpp/imgui_stdlib.cpp
          ${IMGUIDIR}/backends/imgui_impl_glfw.cpp
          ${IMGUIDIR}/backends/imgui_impl_vulkan.cpp)

target_include_directories(imgui PUBLIC ${IMGUIDIR})

target_compile_definitions(imgui PUBLIC GLFW_INCLUDE_VULKAN)

target_link_libraries(imgui PUBLIC glfw Vulkan::Vulkan)

add_library(imguizmo STATIC)

target_sources(imguizmo
               PRIVATE ${FETCHCONTENT_BASE_DIR}/imguizmo-src/ImGuizmo.cpp)

target_include_directories(imguizmo
                           PUBLIC ${FETCHCONTENT_BASE_DIR}/imguizmo-src)

target_link_libraries(imguizmo PUBLIC imgui)

add_library(zEngineLib STATIC)

target_sources(
  zEngineLib
  PRIVATE tests/IntrusiveWeakPtr_test.cpp
          tests/IntrusivePtr_test.cpp
          src/SceneRenderer.cpp
          src/MeshBuilder.cpp
          src/LinkageStage.cpp
          src/VulkanLayer.cpp
          src/CommandBuffer.cpp
          src/PerspectiveCamera.cpp
          src/Engine.cpp
          src/Semaphore.cpp
          src/UIComponent.cpp
          src/GraphicScene.cpp
          src/ShaderManager.cpp
          src/IPipelineStage.cpp
          src/FrameBuffer.cpp
          src/CompilationStage.cpp
          src/Helper.cpp
          src/StandardMaterial.cpp
          src/DirectionalLight.cpp
          src/ValidationStage.cpp
          src/CubeGeometry.cpp
          src/QuadGeometry.cpp
          src/TextureManager.cpp
          src/Attachment.cpp
          src/CameraController.cpp
          src/RendererPipeline.cpp
          src/Shader.cpp
          src/LayerStack.cpp
          src/ShaderCompiler.cpp
          src/Texture2D.cpp
          src/CommandPool.cpp
          src/GraphicScene3DSerializer.cpp
          src/Fence.cpp
          src/VulkanDevice.cpp
          src/ImageMemoryBarrier.cpp
          src/SquareGeometry.cpp
          src/GraphicRenderer.cpp
          src/IDevice.cpp
          src/GraphicVertex.cpp
          src/Logger.cpp
          src/ImGUIRenderer.cpp
          src/PerspectiveCameraController.cpp
          src/ShaderReader.cpp
          src/Mesh.cpp
          src/ShaderMaterial.cpp
          src/GlfwWindow/VulkanWindow.cpp
          src/Image2DBuffer.cpp
          src/BasicMaterial.cpp
          src/GraphicSceneEntity.cpp
          src/Swapchain.cpp
          src/IPipelineContext.cpp
          src/ImguiLayer.cpp
          src/pch.cpp
          src/RenderPass.cpp
          src/CoreWindow.cpp
          src/Math.cpp
          src/GlfwWindow/VulkanWindow.cpp)

target_include_directories(
  zEngineLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/ZEngine
                    ${FETCHCONTENT_BASE_DIR}/stbimage-src)

# target_precompile_headers(zEngineLib PRIVATE
# ${CMAKE_CURRENT_SOURCE_DIR}/include/ZEngine/pch.h)

target_compile_definitions(
  zEngineLib
  PUBLIC ZENGINE_PLATFORM
         # We should control it by using buildEngine parameter
         ENABLE_VULKAN_VALIDATION_LAYER
         ENABLE_VULKAN_SYNCHRONIZATION_LAYER
         YAML_CPP_STATIC_DEFINE)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
  target_compile_definitions(zEngineLib PUBLIC VK_USE_PLATFORM_WIN32_KHR
                                               GLFW_EXPOSE_NATIVE_WIN32)
else()
  # target_compile_definitions(zEngineLib PUBLIC GLFW_NATIVE_INCLUDE_NONE)
  target_compile_definitions(zEngineLib PUBLIC VK_USE_PLATFORM_WAYLAND_KHR
      GLFW_EXPOSE_NATIVE_WAYLAND)
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  target_link_libraries(zEngineLib PRIVATE stdc++fs)
endif()

target_link_libraries(
  zEngineLib
  PUBLIC fmt::fmt
         yaml-cpp::yaml-cpp
         imgui
         imguizmo
         spdlog::spdlog
         glm
         EnTT::EnTT
         assimp::assimp
         stduuid
         GPUOpen::VulkanMemoryAllocator
         spirv-cross-core)
