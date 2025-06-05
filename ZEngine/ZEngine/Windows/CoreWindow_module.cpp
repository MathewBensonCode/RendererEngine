export module ZEngine.Windows.CoreWindow;

import std;
import ZEngine.Core.Containers.Array;
import ZEngine.Core.Containers.Strings;
import ZEngine.Core.CoreEvent;
import ZEngine.Core.EventDispatcher;
import ZEngine.Core.IEventable;
import ZEngine.Core.IInitializable;
import ZEngine.Core.IRenderable;
import ZEngine.Core.IUpdatable;
import ZEngine.Core.Memory.Allocator;
import ZEngine.Core.TimeStep;
import ZEngine.Helpers.IntrusivePtr;
import ZEngine.Windows.Inputs.IInputEventCallback;
import ZEngine.Windows.WindowConfiguration;
import ZEngine.Windows.WindowProperty;

namespace ZEngine::Windows
{
   export class CoreWindow : public Inputs::IKeyboardEventCallback, public Inputs::IMouseEventCallback, public Inputs::ITextInputEventCallback, public Inputs::IWindowEventCallback, public Core::IUpdatable, public Core::IRenderable, public Core::IEventable

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
} // namespace ZEngine::Windows
