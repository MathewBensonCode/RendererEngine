module;

export module ZEngine.Rendering.Components.NameComponent;

import std;



export namespace ZEngine::Rendering::Components
{
    struct NameComponent
    {
        NameComponent() = default;
        NameComponent(std::string_view name) : Name(name) {}
        ~NameComponent() = default;

        std::string Name;
    };
} // namespace ZEngine::Rendering::Components
