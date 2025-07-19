export module ZEngine.Rendering:Windows.IEventable;

import std;
import ZEngine.Core.CoreEvent;

namespace ZEngine::Rendering::Windows
{
    export struct IEventable
    {
        IEventable()          = default;
        virtual ~IEventable() = default;
        ;
        virtual bool OnEvent(ZEngine::Core::CoreEvent&) = 0;
    };
} // namespace ZEngine::Rendering::Windows
