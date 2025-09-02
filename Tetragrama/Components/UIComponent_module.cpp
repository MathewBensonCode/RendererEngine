export module Tetragrama.Components:UIComponent;

import std;
import Tetragrama.Layers;
import ZEngine;


namespace Tetragrama::Components
{
    struct UIComponent : public ZEngine::Windows::IRenderable, public ZEngine::Rendering::Windows::IUpdatable
    {
        UIComponent()          = default;
        virtual ~UIComponent() = default;

        virtual void Initialize(Layers::ImguiLayer* parent, const char* name, bool visibility, bool closed)
        {
            ParentLayer = parent;
            Name        = name;
            IsVisible   = visibility;
            CanBeClosed = closed;
        }

        bool                                                   IsVisible     = true;
        bool                                                   CanBeClosed   = false;
        const char*                                            Name          = "";
        std::uint32_t                                               ChildrenCount = 0;
        Tetragrama::Layers::ImguiLayer*                        ParentLayer   = nullptr;
        ZEngine::Core::Containers::Array<ZRawPtr(UIComponent)> Children      = {};
    };
} // namespace Tetragrama::Components
