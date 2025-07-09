export module ZEngine.Windows:CoreWindow;

import std;
import :WindowConfiguration;
import :WindowProperty;
import ZEngine.Core.Containers.Array;
import ZEngine.Core.Containers.Strings;
import ZEngine.Core.CoreEvent;
import ZEngine.Core.EventDispatcher;
import ZEngine.Core.IInitializable;
import ZEngine.Rendering;
import ZEngine.Core.Memory.Allocator;
import ZEngine.Core.TimeStep;
import ZEngine.Helpers.IntrusivePtr;

namespace ZEngine::Windows
{
  struct IEventable;
  struct IUpdatable;

   export class CoreWindow : public IKeyboardEventCallback, public Inputs::IMouseEventCallback, public Inputs::ITextInputEventCallback, public Inputs::IWindowEventCallback, public IUpdatable, public ZEngine::Rendering::IRenderable, public IEventable

    {

    public:
        using EventCallbackFn = std::function<void(Core::CoreEvent&)>;

    public:
        CoreWindow() {}
        CoreWindow(const WindowConfiguration& cfg);
        virtual ~CoreWindow();

        Core::Containers::Array<const char*> RequiredExtensionLayers                                            = {};

        virtual std::uint32_t                     GetHeight() const                                                  = 0;
        virtual std::uint32_t                     GetWidth() const                                                   = 0;
        virtual Core::Containers::StringView GetTitle() const                                                   = 0;
        virtual void                         SetTitle(Core::Containers::StringView title)                       = 0;
        virtual bool                         IsMinimized() const                                                = 0;

        virtual bool                         IsVSyncEnable() const                                              = 0;
        virtual void                         SetVSync(bool value)                                               = 0;
        virtual void                         SetCallbackFunction(const EventCallbackFn& callback)               = 0;
        virtual const WindowProperty&        GetWindowProperty() const                                          = 0;

        virtual bool                         CreateSurface(void* instance, void** out_window_surface)           = 0;
        virtual void*                        GetNativeWindow() const                                            = 0;

        virtual std::future<std::string>     OpenFileDialogAsync(std::span<std::string_view> type_filters = {}) = 0;

        virtual void                         PollEvent()                                                        = 0;
        virtual float                        GetTime()                                                          = 0;
        virtual float                        GetDeltaTime()                                                     = 0;

        virtual void                         ForwardEventToLayers(Core::CoreEvent& event);

        virtual void                         Deinitialize() {}

    protected:
        Core::TimeStep      m_delta_time;
        WindowProperty      m_property;
        WindowConfiguration m_configuration;
    };

    CoreWindow* Create(Core::Memory::ArenaAllocator* arena, const WindowConfiguration& cfg);

    CoreWindow::CoreWindow(const WindowConfiguration& cfg) : m_configuration(cfg) {}

    CoreWindow::~CoreWindow() {}

    void CoreWindow::ForwardEventToLayers(Core::CoreEvent& event)
    {
        for (auto layer : m_configuration.OverlayLayerCollection)
        {
            if (event.IsHandled())
            {
                break;
            }
            layer->OnEvent(event);
        }

        for (auto layer : m_configuration.RenderingLayerCollection)
        {
            if (event.IsHandled())
            {
                break;
            }
            layer->OnEvent(event);
        }
    }
} // namespace ZEngine::Windows
