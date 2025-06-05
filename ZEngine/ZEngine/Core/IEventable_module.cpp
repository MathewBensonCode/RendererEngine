export module ZEngine.Core.IEventable;

import std;
import ZEngine.Core.CoreEvent;

export namespace ZEngine::Core
{

    struct IEventable
    {
        IEventable()                     = default;
        virtual ~IEventable()            = default;

        virtual bool OnEvent(CoreEvent&) = 0;
    };
} // namespace ZEngine::Core
