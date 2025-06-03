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

target_compile_definitions(imgui PUBLIC GLFW_INCLUDE_VULKAN IMGUI_DEFINE_MATH_OPERATORS)

target_link_libraries(imgui PUBLIC glfw Vulkan::Vulkan)

add_library(imguizmo STATIC)

target_sources(imguizmo
               PRIVATE ${FETCHCONTENT_BASE_DIR}/imguizmo-src/ImGuizmo.cpp)

target_include_directories(imguizmo
                           PUBLIC ${FETCHCONTENT_BASE_DIR}/imguizmo-src)

target_link_libraries(imguizmo PUBLIC imgui)

add_library(zEngineLib STATIC)

target_include_directories(zEngineLib
                                PUBLIC
                                ${FETCHCONTENT_BASE_DIR}/tlsf-src
                                ${FETCHCONTENT_BASE_DIR}/stbimage-src
                                ${CMAKE_CURRENT_SOURCE_DIR}
                                ${FETCHCONTENT_BASE_DIR}/rapidhash-src
                       )

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
         SPIRV-Tools
         glslang::glslang
         glslang::glslang-default-resource-limits
         glslang::SPIRV
         glslang::SPVRemapper
         GPUOpen::VulkanMemoryAllocator
         CLI11::CLI11
     )

# ZEngine source files
#

target_sources(
  zEngineLib
      PRIVATE 
      ZEngine/Engine.cpp
      ZEngine/Windows/Inputs/IDevice.cpp
      ZEngine/Windows/CoreWindow.cpp
      ZEngine/Helpers/ThreadPool.cpp
      ZEngine/Helpers/Helper.cpp
      ZEngine/Logging/Logger.cpp
      ZEngine/Serializers/GraphicScene3DSerializer.cpp
      ZEngine/Core/IPipelineStage.cpp
      ZEngine/Core/CoroutineScheduler.cpp
      ZEngine/Core/Memory/Allocator.cpp
      ZEngine/Core/IPipelineContext.cpp
      ZEngine/Hardwares/VulkanLayer.cpp
      ZEngine/Hardwares/VulkanDevice.cpp
      ZEngine/Maths/Math.cpp
      ZEngine/Rendering/Primitives/Semaphore.cpp
      ZEngine/Rendering/Primitives/Fence.cpp
      ZEngine/Rendering/Primitives/ImageMemoryBarrier.cpp
      ZEngine/Rendering/Scenes/GraphicScene.cpp
      ZEngine/Rendering/Meshes/MeshBuilder.cpp
      ZEngine/Rendering/Shaders/Compilers/CompilationStage.cpp
      ZEngine/Rendering/Shaders/Compilers/ValidationStage.cpp
      ZEngine/Rendering/Shaders/Compilers/ShaderFileGenerator.cpp
      ZEngine/Rendering/Shaders/Compilers/ShaderCompiler.cpp
      ZEngine/Rendering/Shaders/Shader.cpp
      ZEngine/Rendering/Shaders/ShaderReader.cpp
      ZEngine/Rendering/Geometries/CubeGeometry.cpp
      ZEngine/Rendering/Geometries/QuadGeometry.cpp
      ZEngine/Rendering/Geometries/SquareGeometry.cpp
      ZEngine/Rendering/Entities/GraphicSceneEntity.cpp
      ZEngine/Rendering/Renderers/RenderGraph.cpp
      ZEngine/Rendering/Renderers/GraphicRenderer.cpp
      ZEngine/Rendering/Renderers/RenderPasses/Attachment.cpp
      ZEngine/Rendering/Renderers/RenderPasses/RenderPass.cpp
      ZEngine/Rendering/Renderers/ImGUIRenderer.cpp
      ZEngine/Rendering/Renderers/Storages/GraphicVertex.cpp
      ZEngine/Rendering/Renderers/Pipelines/RendererPipeline.cpp
      ZEngine/Rendering/Renderers/RendererPasses.cpp
      ZEngine/Rendering/Cameras/PerspectiveCamera.cpp
      ZEngine/Rendering/Pools/CommandPool.cpp
      ZEngine/Rendering/Buffers/FrameBuffer.cpp
      ZEngine/Rendering/Textures/Texture2D.cpp
      ZEngine/Rendering/Textures/Texture.cpp
      ZEngine/Rendering/Materials/StandardMaterial.cpp
      ZEngine/Rendering/Materials/ShaderMaterial.cpp
      ZEngine/Rendering/Materials/BasicMaterial.cpp
  )


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
