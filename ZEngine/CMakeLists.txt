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

target_include_directories(
  zEngineLib
  PUBLIC ${FETCHCONTENT_BASE_DIR}/tlsf-src
         ${FETCHCONTENT_BASE_DIR}/stbimage-src ${CMAKE_CURRENT_SOURCE_DIR}
         ${FETCHCONTENT_BASE_DIR}/rapidhash-src)

target_link_libraries(
  zEngineLib
  PUBLIC 
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
         CLI11::CLI11)

# ZEngine source files
#

target_sources(
  zEngineLib
  PUBLIC
    FILE_SET
    modules
    TYPE
    CXX_MODULES
    FILES
    ZEngine/Engine_module.cpp
    ZEngine/Event/EngineClosedEvent_module.cpp
    ZEngine/ZEngineDef_module.cpp
    ZEngine/Helpers/MathHelper_module.cpp
    ZEngine/Helpers/ContainerExtension_module.cpp
    ZEngine/Helpers/ThreadSafeQueue_module.cpp
    ZEngine/Helpers/ThreadPool_module.cpp
    ZEngine/Helpers/HandleManager_module.cpp
    ZEngine/Helpers/IntrusivePtr_module.cpp
    ZEngine/Helpers/MemoryOperations_module.cpp
    ZEngine/Logging/LoggerConfiguration_module.cpp
    ZEngine/Logging/Logger_module.cpp
    ZEngine/Logging/Logging_module.cpp
    ZEngine/Core/CoroutineScheduler_module.cpp
    ZEngine/Core/ISerializer_module.cpp
    ZEngine/Core/IGraphicObject_module.cpp
    ZEngine/Core/CoreEvent_module.cpp
    ZEngine/Core/TimeStep_module.cpp
    ZEngine/Core/EventDispatcher_module.cpp
    ZEngine/Core/Memory/Allocator_module.cpp
    ZEngine/Core/Memory/MemoryManager_module.cpp
    ZEngine/Core/Utility_module.cpp
    ZEngine/Core/Coroutine_module.cpp
    ZEngine/Core/Containers/InitializerList_module.cpp
    ZEngine/Core/Containers/Strings_module.cpp
    ZEngine/Core/Containers/Array_module.cpp
    ZEngine/Core/Containers/HashMap_module.cpp
    ZEngine/Core/IInitializable_module.cpp
    ZEngine/Core/Maths/Matrix_module.cpp
    ZEngine/Core/Maths/Vec_module.cpp
    ZEngine/Core/IPipeline_module.cpp
    ZEngine/EngineConfiguration_module.cpp
    ZEngine/Maths/Math_module.cpp
    ZEngine/Rendering/IRenderable_module.cpp
    ZEngine/Rendering/Rendering_module.cpp
    ZEngine/Rendering/Devices/VulkanLayer_module.cpp
    ZEngine/Rendering/Devices/VulkanDevice_module.cpp
    ZEngine/Rendering/Primitives/Semaphore_module.cpp
    ZEngine/Rendering/Primitives/Fence_module.cpp
    ZEngine/Rendering/Primitives/ImageMemoryBarrier_module.cpp
    ZEngine/Rendering/ResourceTypes_module.cpp
    ZEngine/Rendering/Scenes/GraphicScene_module.cpp
    #ZEngine/Rendering/Meshes/MeshLight_module.cpp
    #ZEngine/Rendering/Meshes/MeshBuilder_module.cpp
    ZEngine/Rendering/Meshes/Mesh_module.cpp
    ZEngine/Rendering/Meshes/MeshHelper_module.cpp
    ZEngine/Rendering/Shaders/ShaderReader_module.cpp
    ZEngine/Rendering/Shaders/Compilers/ICompilerStage_module.cpp
    ZEngine/Rendering/Shaders/Compilers/ShaderCompiler_module.cpp
    ZEngine/Rendering/Shaders/Compilers/ShaderFileGenerator_module.cpp
    ZEngine/Rendering/Shaders/Compilers/CompilationStage_module.cpp
    ZEngine/Rendering/Shaders/Compilers/ValidationStage_module.cpp
    ZEngine/Rendering/Shaders/Shader_module.cpp
    ZEngine/Rendering/Shaders/ShaderIncluder_module.cpp
    ZEngine/Rendering/Shaders/ShaderEnums_module.cpp
    ZEngine/Rendering/Shaders/ShaderInformation_module.cpp
    ZEngine/Rendering/Lights/Light_module.cpp
    ZEngine/Rendering/Geometries/IGeometry_module.cpp
    ZEngine/Rendering/Geometries/GeometryEnum_module.cpp
    ZEngine/Rendering/Geometries/SquareGeometry_module.cpp
    ZEngine/Rendering/Geometries/QuadGeometry_module.cpp
    ZEngine/Rendering/Geometries/CubeGeometry_module.cpp
    ZEngine/Rendering/Entities/GraphicSceneEntity_module.cpp
    ZEngine/Rendering/Specifications/RenderPassSpecification_module.cpp
    ZEngine/Rendering/Specifications/ShaderSpecification_module.cpp
    ZEngine/Rendering/Specifications/ImageMemoryBarrierSpecification_module.cpp
    ZEngine/Rendering/Specifications/AttachmentSpecification_module.cpp
    ZEngine/Rendering/Specifications/FrameBufferSpecification_module.cpp
    ZEngine/Rendering/Specifications/FormatSpecification_module.cpp
    ZEngine/Rendering/Specifications/TextureSpecification_module.cpp
    ZEngine/Rendering/Specifications/GraphicRendererPipelineSpecification_module.cpp
    ZEngine/Rendering/Renderers/RendererPasses_module.cpp
    #    ZEngine/Rendering/Renderers/GraphicRendererInformation_module.cpp
    ZEngine/Rendering/Renderers/RenderGraph_module.cpp
    ZEngine/Rendering/Renderers/GraphicRenderer_module.cpp
    ZEngine/Rendering/Renderers/RenderPasses/Attachment_module.cpp
    ZEngine/Rendering/Renderers/RenderPasses/RenderPass_module.cpp
    ZEngine/Rendering/Renderers/Storages/IVertex_module.cpp
    ZEngine/Rendering/Renderers/Storages/GraphicVertex_module.cpp
    ZEngine/Rendering/Renderers/Pipelines/IGraphicRendererPipelineStage_module.cpp
    ZEngine/Rendering/Renderers/Pipelines/RendererPipeline_module.cpp
    ZEngine/Rendering/Renderers/Pipelines/GraphicRendererPipelineInformation_module.cpp
    ZEngine/Rendering/Renderers/ImGUIRenderer_module.cpp
    ZEngine/Rendering/Renderers/Contracts/RendererDataContract_module.cpp
    ZEngine/Rendering/Cameras/PerspectiveCamera_module.cpp
    ZEngine/Rendering/Cameras/Camera_module.cpp
    ZEngine/Rendering/Cameras/CameraEnum_module.cpp
    ZEngine/Rendering/Pools/CommandPool_module.cpp
    ZEngine/Rendering/GPUTypes_module.cpp
    ZEngine/Rendering/Buffers/Framebuffer_module.cpp
    ZEngine/Rendering/Buffers/Bitmap_module.cpp
    ZEngine/Rendering/Buffers/PixelBuffer_module.cpp
    ZEngine/Rendering/Buffers/BufferLayout_module.cpp
    ZEngine/Rendering/Textures/Texture_module.cpp
    #ZEngine/Rendering/Textures/Texture2D_module.cpp
    ZEngine/Rendering/Materials/ShaderMaterial_module.cpp
    ZEngine/Rendering/Materials/IMaterial_module.cpp
    ZEngine/Rendering/Materials/BasicMaterial_module.cpp
    ZEngine/Rendering/Materials/StandardMaterial_module.cpp
    ZEngine/Rendering/Components/ValidComponent_module.cpp
    ZEngine/Rendering/Components/NameComponent_module.cpp
    #ZEngine/Rendering/Components/CameraComponent_module.cpp
    ZEngine/Rendering/Components/UUIComponent_module.cpp
    ZEngine/Rendering/Components/GeometryComponent_module.cpp
    ZEngine/Rendering/Components/TransformComponent_module.cpp
    ZEngine/Rendering/Components/MaterialComponent_module.cpp
    ZEngine/Rendering/Components/LightComponent_module.cpp
    ZEngine/Rendering/Serializers/GraphicScene3DSerializer_module.cpp
    ZEngine/Rendering/Serializers/GraphicSceneSerializer_module.cpp
    ZEngine/Rendering/Windows/WindowConfiguration_module.cpp
    ZEngine/Rendering/Windows/CoreWindow_module.cpp
    ZEngine/Rendering/Windows/WindowProperty_module.cpp
    ZEngine/Rendering/Windows/Events/WindowEvent_module.cpp
    ZEngine/Rendering/Windows/Events/KeyEvent_module.cpp
    ZEngine/Rendering/Windows/Events/MouseEvent_module.cpp
    ZEngine/Rendering/Windows/Events/TextInputEvent_module.cpp
    ZEngine/Rendering/Windows/Inputs/KeyCodeDefinition_module.cpp
    ZEngine/Rendering/Windows/Inputs/KeyCode_module.cpp
    ZEngine/Rendering/Windows/Inputs/IInputEventCallback_module.cpp
    ZEngine/Rendering/Windows/Inputs/IDevice_module.cpp
    ZEngine/Rendering/Windows/IUpdatable_module.cpp
    ZEngine/Rendering/Windows/IEventable_module.cpp

  PRIVATE ZEngine/Engine.cpp
          ZEngine/Helpers/ThreadPool.cpp
          ZEngine/Helpers/Helper.cpp
          ZEngine/Logging/Logger.cpp
          ZEngine/Core/IPipelineStage.cpp
          ZEngine/Core/CoroutineScheduler.cpp
          ZEngine/Core/Memory/Allocator.cpp
          ZEngine/Core/IPipelineContext.cpp
          ZEngine/Rendering/Devices/VulkanLayer.cpp
          ZEngine/Rendering/Devices/VulkanDevice.cpp
          ZEngine/Maths/Math.cpp
          ZEngine/Rendering/Scenes/GraphicScene.cpp
          #ZEngine/Rendering/Meshes/MeshBuilder.cpp
          ZEngine/Rendering/Shaders/Compilers/CompilationStage.cpp
          ZEngine/Rendering/Shaders/Compilers/ValidationStage.cpp
          ZEngine/Rendering/Shaders/Compilers/ShaderFileGenerator.cpp
          ZEngine/Rendering/Shaders/Compilers/ShaderCompiler.cpp
          ZEngine/Rendering/Shaders/Shader.cpp
          ZEngine/Rendering/Shaders/ShaderReader.cpp
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
          #      ZEngine/Rendering/Textures/Texture2D.cpp
          ZEngine/Rendering/Textures/Texture.cpp
          ZEngine/Rendering/Serializers/GraphicScene3DSerializer.cpp
      )

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  target_compile_definitions(zEngineLib PUBLIC ENABLE_VULKAN_VALIDATION_LAYER)
endif()

target_compile_definitions(
  zEngineLib PUBLIC ZENGINE_PLATFORM ENABLE_VULKAN_SYNCHRONIZATION_LAYER
                    YAML_CPP_STATIC_DEFINE)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
  target_compile_definitions(zEngineLib PUBLIC VK_USE_PLATFORM_WIN32_KHR
                                               NOMINMAX)
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  target_link_libraries(zEngineLib PRIVATE stdc++fs)
endif()

target_compile_definitions(zEngineLib PUBLIC GLM_ENABLE_EXPERIMENTAL)

#add_subdirectory(tests)
