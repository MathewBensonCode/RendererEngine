cmake_minimum_required(VERSION 3.17)

project(
  ZEngine
  VERSION 1.0
  DESCRIPTION
    "ZEngine is the core engine lib that provides abstraction on top of OpenGL/DirectX/Metal"
  LANGUAGES CXX)

find_package(Vulkan REQUIRED)

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

target_include_directories(zEngineLib
                           PUBLIC ${FETCHCONTENT_BASE_DIR}/stbimage-src)

target_link_libraries(
  zEngineLib
  PUBLIC fmt::fmt
         glm::glm
         imguizmo
         spdlog::spdlog
         EnTT::EnTT
         assimp::assimp
         stduuid
         yaml-cpp::yaml-cpp
         spirv-cross-core
         SPIRV-Tools-static
         SPIRV-Tools-opt
         glslang::glslang
         glslang::glslang-default-resource-limits
         glslang::SPIRV
         glslang::SPVRemapper
         GPUOpen::VulkanMemoryAllocator)

# ZEngine source files
#

target_sources(
  zEngineLib
  PRIVATE src/Attachment.cpp
          src/BasicMaterial.cpp
          src/CameraController.cpp
          src/CommandBuffer.cpp
          src/CommandPool.cpp
          src/CompilationStage.cpp
          src/CoreWindow.cpp
          src/CoroutineScheduler.cpp
          src/CubeGeometry.cpp
          src/Engine.cpp
          src/Fence.cpp
          src/FrameBuffer.cpp
          src/GraphicRenderer.cpp
          src/GraphicScene3DSerializer.cpp
          src/GraphicScene.cpp
          src/GraphicSceneEntity.cpp
          src/GraphicVertex.cpp
          src/Helper.cpp
          src/IDevice.cpp
          src/Image2DBuffer.cpp
          src/ImageMemoryBarrier.cpp
          src/ImguiLayer.cpp
          src/ImGUIRenderer.cpp
          src/IPipelineContext.cpp
          src/IPipelineStage.cpp
          src/LayerStack.cpp
          src/Logger.cpp
          src/Math.cpp
          src/MeshBuilder.cpp
          src/PerspectiveCameraController.cpp
          src/PerspectiveCamera.cpp
          src/QuadGeometry.cpp
          src/RendererPipeline.cpp
          src/RenderGraph.cpp
          src/RenderPass.cpp
          src/SceneRenderer.cpp
          src/Semaphore.cpp
          src/ShaderCompiler.cpp
          src/Shader.cpp
          src/ShaderFileGenerator.cpp
          src/ShaderManager.cpp
          src/ShaderMaterial.cpp
          src/ShaderReader.cpp
          src/SquareGeometry.cpp
          src/StandardMaterial.cpp
          src/Swapchain.cpp
          src/Texture2D.cpp
          src/TextureManager.cpp
          src/ThreadPool.cpp
          src/UIComponent.cpp
          src/ValidationStage.cpp
          src/VulkanDevice.cpp
          src/VulkanLayer.cpp
          src/GlfwWindow/VulkanWindow.cpp)

target_include_directories(zEngineLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  target_compile_definitions(zEngineLib PUBLIC ENABLE_VULKAN_VALIDATION_LAYER)
endif()

target_compile_definitions(
  zEngineLib PUBLIC ZENGINE_PLATFORM ENABLE_VULKAN_SYNCHRONIZATION_LAYER
                    YAML_CPP_STATIC_DEFINE)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    target_compile_definitions(zEngineLib PUBLIC VK_USE_PLATFORM_WIN32_KHR NOMINMAX)
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  target_link_libraries(zEngineLib PRIVATE stdc++fs)
endif()

target_compile_definitions(zEngineLib PUBLIC GLM_ENABLE_EXPERIMENTAL)

add_subdirectory(tests)
