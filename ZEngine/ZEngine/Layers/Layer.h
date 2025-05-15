#pragma once
#include <ZEngine/Core/IEventable.h>
#include <ZEngine/Core/IInitializable.h>
#include <ZEngine/Core/IRenderable.h>
#include <ZEngine/Core/IUpdatable.h>
#include <ZEngine/Core/TimeStep.h>
#include <ZEngine/Event/CoreEvent.h>
#include <ZEngine/Window/CoreWindow.h>
#include <ZEngine/ZEngineDef.h>
#include <vulkan/vulkan.h>
#include <string>
#include <string_view>

namespace ZEngine::Window
{
    class CoreWindow;
}

namespace ZEngine::Layers
{

    class Layer : public Core::IInitializable, public Core::IUpdatable, public Core::IEventable, public Core::IRenderable, public Helpers::RefCounted
    {

    public:
        Layer(std::string_view name = "default_layer") : m_name(name) {}

        virtual ~Layer() = default;

        std::string_view GetName() const
        {
            return m_name;
        }

        void SetAttachedWindow(const ZEngine::Ref<Window::CoreWindow>& window)
        {
            m_window = window;
        }

        ZEngine::Ref<ZEngine::Window::CoreWindow> GetAttachedWindow() const
        {
            if (!m_window.expired())
                return m_window.lock();

            return nullptr;
        }

    protected:
        std::string                                   m_name;
        ZEngine::WeakRef<ZEngine::Window::CoreWindow> m_window;
    };
} // namespace ZEngine::Layers
