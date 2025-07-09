export module ZEngine.Rendering:Components.ValidComponent;

import std;

export namespace ZEngine::Rendering::Components
{
    struct ValidComponent
    {
        ValidComponent() = default;
        ValidComponent(bool value) : IsValid(value) {}
        ~ValidComponent() = default;

        bool IsValid{true};
    };
} // namespace ZEngine::Rendering::Components
