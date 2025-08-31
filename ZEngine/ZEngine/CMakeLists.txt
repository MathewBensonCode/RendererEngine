project(
  ZEngine
  VERSION 1.0
  DESCRIPTION
    "ZEngine is the core engine lib that provides abstraction on top of OpenGL/DirectX/Metal"
  LANGUAGES CXX)

add_library(zEngineLib STATIC)

target_link_libraries(
  zEngineLib
  PUBLIC 
imported::External_libs
)

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
    ZEngine_module.cpp
    Core/Core_module.cpp
    Engine_module.cpp
    Event/EngineClosedEvent_module.cpp
    ZEngineDef_module.cpp
    Helpers/Helpers_module.cpp
    Helpers/MathHelper_module.cpp
    Helpers/ContainerExtension_module.cpp
    Helpers/ThreadSafeQueue_module.cpp
    Helpers/ThreadPool_module.cpp
    Helpers/HandleManager_module.cpp
    Helpers/IntrusivePtr_module.cpp
    Helpers/MemoryOperations_module.cpp
    Logging/LoggerConfiguration_module.cpp
    Logging/Logger_module.cpp
    Logging/Logging_module.cpp
    Core/CoroutineScheduler_module.cpp
    Core/ISerializer_module.cpp
    Core/IGraphicObject_module.cpp
    Core/CoreEvent_module.cpp
    Core/TimeStep_module.cpp
    Core/EventDispatcher_module.cpp
    Core/Memory/Allocator_module.cpp
    Core/Memory/MemoryManager_module.cpp
    Core/Utility_module.cpp
    Core/Coroutine_module.cpp
    Core/Containers/InitializerList_module.cpp
    Core/Containers/Strings_module.cpp
    Core/Containers/Array_module.cpp
    Core/Containers/HashMap_module.cpp
    Core/IInitializable_module.cpp
    Core/Maths/Matrix_module.cpp
    Core/Maths/Vec_module.cpp
    Core/IPipeline_module.cpp
    EngineConfiguration_module.cpp
    Maths/Math_module.cpp
    Rendering/IRenderable_module.cpp
    Rendering/Rendering_module.cpp
    Rendering/Devices/VulkanLayer_module.cpp
    Rendering/Devices/VulkanDevice_module.cpp
    Rendering/Primitives/Semaphore_module.cpp
    Rendering/Primitives/Fence_module.cpp
    Rendering/Primitives/ImageMemoryBarrier_module.cpp
    Rendering/ResourceTypes_module.cpp
    Rendering/Scenes/GraphicScene_module.cpp
    #Rendering/Meshes/MeshLight_module.cpp
    #Rendering/Meshes/MeshBuilder_module.cpp
    Rendering/Meshes/Mesh_module.cpp
    Rendering/Meshes/MeshHelper_module.cpp
    Rendering/Shaders/ShaderReader_module.cpp
    Rendering/Shaders/Compilers/ICompilerStage_module.cpp
    Rendering/Shaders/Compilers/ShaderCompiler_module.cpp
    Rendering/Shaders/Compilers/ShaderFileGenerator_module.cpp
    Rendering/Shaders/Compilers/CompilationStage_module.cpp
    Rendering/Shaders/Compilers/ValidationStage_module.cpp
    Rendering/Shaders/Shader_module.cpp
    Rendering/Shaders/ShaderIncluder_module.cpp
    Rendering/Shaders/ShaderEnums_module.cpp
    Rendering/Shaders/ShaderInformation_module.cpp
    Rendering/Lights/Light_module.cpp
    Rendering/Geometries/IGeometry_module.cpp
    Rendering/Geometries/GeometryEnum_module.cpp
    Rendering/Geometries/SquareGeometry_module.cpp
    Rendering/Geometries/QuadGeometry_module.cpp
    Rendering/Geometries/CubeGeometry_module.cpp
    Rendering/Entities/GraphicSceneEntity_module.cpp
    Rendering/Specifications/RenderPassSpecification_module.cpp
    Rendering/Specifications/ShaderSpecification_module.cpp
    Rendering/Specifications/ImageMemoryBarrierSpecification_module.cpp
    Rendering/Specifications/AttachmentSpecification_module.cpp
    Rendering/Specifications/FrameBufferSpecification_module.cpp
    Rendering/Specifications/FormatSpecification_module.cpp
    Rendering/Specifications/TextureSpecification_module.cpp
    Rendering/Specifications/GraphicRendererPipelineSpecification_module.cpp
    Rendering/Renderers/RendererPasses_module.cpp
    #    Rendering/Renderers/GraphicRendererInformation_module.cpp
    Rendering/Renderers/RenderGraph_module.cpp
    Rendering/Renderers/GraphicRenderer_module.cpp
    Rendering/Renderers/RenderPasses/Attachment_module.cpp
    Rendering/Renderers/RenderPasses/RenderPass_module.cpp
    Rendering/Renderers/Storages/IVertex_module.cpp
    Rendering/Renderers/Storages/GraphicVertex_module.cpp
    Rendering/Renderers/Pipelines/IGraphicRendererPipelineStage_module.cpp
    Rendering/Renderers/Pipelines/RendererPipeline_module.cpp
    Rendering/Renderers/Pipelines/GraphicRendererPipelineInformation_module.cpp
    Rendering/Renderers/ImGUIRenderer_module.cpp
    Rendering/Renderers/Contracts/RendererDataContract_module.cpp
    Rendering/Cameras/PerspectiveCamera_module.cpp
    Rendering/Cameras/Camera_module.cpp
    Rendering/Cameras/CameraEnum_module.cpp
    Rendering/Pools/CommandPool_module.cpp
    Rendering/GPUTypes_module.cpp
    Rendering/Buffers/FrameBuffer_module.cpp
    Rendering/Buffers/Bitmap_module.cpp
    Rendering/Buffers/PixelBuffer_module.cpp
    Rendering/Buffers/BufferLayout_module.cpp
    Rendering/Textures/Texture_module.cpp
    #Rendering/Textures/Texture2D_module.cpp
    Rendering/Materials/ShaderMaterial_module.cpp
    Rendering/Materials/IMaterial_module.cpp
    Rendering/Materials/BasicMaterial_module.cpp
    Rendering/Materials/StandardMaterial_module.cpp
    Rendering/Components/ValidComponent_module.cpp
    Rendering/Components/NameComponent_module.cpp
    #Rendering/Components/CameraComponent_module.cpp
    Rendering/Components/UUIComponent_module.cpp
    Rendering/Components/GeometryComponent_module.cpp
    Rendering/Components/TransformComponent_module.cpp
    Rendering/Components/MaterialComponent_module.cpp
    Rendering/Components/LightComponent_module.cpp
    Rendering/Serializers/GraphicScene3DSerializer_module.cpp
    Rendering/Serializers/GraphicSceneSerializer_module.cpp
    Rendering/Windows/WindowConfiguration_module.cpp
    Rendering/Windows/CoreWindow_module.cpp
    Rendering/Windows/WindowProperty_module.cpp
    Rendering/Windows/Events/WindowEvent_module.cpp
    Rendering/Windows/Events/KeyEvent_module.cpp
    Rendering/Windows/Events/MouseEvent_module.cpp
    Rendering/Windows/Events/TextInputEvent_module.cpp
    Rendering/Windows/Inputs/KeyCodeDefinition_module.cpp
    Rendering/Windows/Inputs/KeyCode_module.cpp
    Rendering/Windows/Inputs/IInputEventCallback_module.cpp
    Rendering/Windows/Inputs/IDevice_module.cpp
    Rendering/Windows/IUpdatable_module.cpp
    Rendering/Windows/IEventable_module.cpp

  PRIVATE Engine.cpp
          Helpers/ThreadPool.cpp
          Helpers/Helper.cpp
          Logging/Logger.cpp
          Core/IPipelineStage.cpp
          Core/CoroutineScheduler.cpp
          Core/Memory/Allocator.cpp
          Core/IPipelineContext.cpp
          Rendering/Devices/VulkanLayer.cpp
          Rendering/Devices/VulkanDevice.cpp
          Rendering/Devices/VmaUsage.cpp
          Maths/Math.cpp
          Rendering/Scenes/GraphicScene.cpp
          #Rendering/Meshes/MeshBuilder.cpp
          Rendering/Shaders/Compilers/CompilationStage.cpp
          Rendering/Shaders/Compilers/ValidationStage.cpp
          Rendering/Shaders/Compilers/ShaderFileGenerator.cpp
          Rendering/Shaders/Compilers/ShaderCompiler.cpp
          Rendering/Shaders/Shader.cpp
          Rendering/Shaders/ShaderReader.cpp
          Rendering/Entities/GraphicSceneEntity.cpp
          Rendering/Renderers/RenderGraph.cpp
          Rendering/Renderers/GraphicRenderer.cpp
          Rendering/Renderers/RenderPasses/Attachment.cpp
          Rendering/Renderers/RenderPasses/RenderPass.cpp
          Rendering/Renderers/ImGUIRenderer.cpp
          Rendering/Renderers/Storages/GraphicVertex.cpp
          Rendering/Renderers/Pipelines/RendererPipeline.cpp
          Rendering/Renderers/RendererPasses.cpp
          Rendering/Cameras/PerspectiveCamera.cpp
          Rendering/Pools/CommandPool.cpp
          Rendering/Buffers/FrameBuffer.cpp
          Rendering/Primitives/ImageMemoryBarrier.cpp
          Rendering/Primitives/Fence.cpp
          Rendering/Primitives/Semaphore.cpp
          #      Rendering/Textures/Texture2D.cpp
          Rendering/Textures/Texture.cpp
          Rendering/Serializers/GraphicScene3DSerializer.cpp
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
