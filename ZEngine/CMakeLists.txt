cmake_minimum_required (VERSION 3.17)

project (ZEngine 
	VERSION 1.0
	DESCRIPTION "ZEngine is the core engine lib that provides abstraction on top of OpenGL/DirectX/Metal"
	LANGUAGES CXX C
)

# Compiler verification in Linux
#


# ZEngine source files
#

add_library (zEngineLib
	STATIC
)

target_sources(zEngineLib PRIVATE 
src/Attachment.cpp
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
src/GlfwWindow/VulkanWindow.cpp
)

target_include_directories (zEngineLib
	PUBLIC 
		include/
        include/ZEngine/
)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	target_compile_definitions (zEngineLib PUBLIC ENABLE_VULKAN_VALIDATION_LAYER)
endif()

target_compile_definitions (zEngineLib
	PUBLIC
		ZENGINE_PLATFORM
		ENABLE_VULKAN_SYNCHRONIZATION_LAYER
		YAML_CPP_STATIC_DEFINE
)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	target_compile_definitions (zEngineLib PUBLIC VK_USE_PLATFORM_WIN32_KHR)
endif()

if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	target_link_libraries(zEngineLib PRIVATE stdc++fs)
endif ()

target_compile_definitions(zEngineLib PUBLIC GLM_ENABLE_EXPERIMENTAL)
target_link_libraries (zEngineLib PUBLIC imported::External_libs)

add_subdirectory(tests)
