export module ZEngine.Core.IUpdatable;

import std;
import ZEngine.Core.TimeStep;

export namespace ZEngine::Core
{

    struct IUpdatable
    {
        IUpdatable()                     = default;
        virtual ~IUpdatable()            = default;

        virtual void Update(TimeStep dt) = 0;
    };
} // namespace ZEngine::Core
