export module ZEngine.Rendering:Windows.IUpdatable;

import std;
import ZEngine.Core.TimeStep;

namespace ZEngine::Rendering::Windows
{
    export struct IUpdatable
    {
        IUpdatable()                     = default;
        virtual ~IUpdatable()            = default;

        virtual void Update(Core::TimeStep dt) = 0;
    };
} // namespace ZEngine::Core
