module ZEngine.Engine;

import std;
import ZEngine.Rendering;
import ZEngine.Logging;
import ZEngine.Core.Memory.Allocator;
import ZEngine.ZEngineDef;

namespace ZEngine
{
    static bool              s_request_terminate                     = false;
    static std::shared_mutex g_mutex                                 = {};
    static Rendering::Windows::CoreWindow* g_current_window             = nullptr;
    static Rendering::Renderers::GraphicRenderer* g_renderer = nullptr;
    static Rendering::Devices::VulkanDevice* g_device                 = nullptr;

    void Engine::Initialize(ZEngine::Core::Memory::ArenaAllocator* arena, ZEngine::Rendering::Windows::CoreWindow* window) 
    {
        g_current_window = window;
        g_device         = ZPushStructCtor<Rendering::Devices::VulkanDevice>(arena);
        g_renderer       = ZPushStructCtor<Rendering::Renderers::GraphicRenderer>(arena);

        g_device->Initialize(arena, window);
        g_renderer->Initialize(g_device);

        ZEngine::Logging::Logger::Info("Engine initialized");
    }

    void Engine::Deinitialize()
    {
        std::unique_lock l(g_mutex);
        if (g_current_window)
        {
            g_current_window->Deinitialize();
        }
        g_renderer->Deinitialize();

        g_device->Deinitialize();
    }

    void Engine::Dispose()
    {
        s_request_terminate = false;
        g_device->Dispose();

        ZEngine::Logging::Logger::Info("Engine destroyed");
    }

    bool Engine::OnEngineClosed(Event::EngineClosedEvent& event)
    {
        s_request_terminate = true;
        return true;
    }

    void Engine::Run()
    {
        s_request_terminate = false;
        while (g_current_window)
        {
            if (s_request_terminate)
            {
                break;
            }

            float dt = g_current_window->GetDeltaTime();

            g_current_window->PollEvent();

            if (g_current_window->IsMinimized())
            {
                continue;
            }

            /*On Update*/
            g_current_window->Update(dt);

            g_device->Update();
            if (g_renderer->EnqueuedResizeRequests.Size())
            {
                Rendering::Renderers::ResizeRequest req;
                if (g_renderer->EnqueuedResizeRequests.Pop(req))
                {
                    g_renderer->RenderGraph->Resize(req.Width, req.Height);
                    continue;
                }
            }

            /*On Render*/
            g_device->NewFrame();
            g_renderer->ImguiRenderer->NewFrame();
            auto buffer = g_device->GetCommandBuffer();
            {

                g_current_window->Render(g_renderer, buffer);

                g_renderer->ImguiRenderer->DrawFrame(g_device->CurrentFrameIndex, buffer);
            }
            g_device->EnqueueCommandBuffer(buffer);
            g_device->Present();
        }

        if (s_request_terminate)
        {
            Deinitialize();
        }
    }

    Rendering::Windows::CoreWindow* Engine::GetWindow()
    {
        std::shared_lock l(g_mutex);
        return g_current_window;
    }
} // namespace ZEngine
