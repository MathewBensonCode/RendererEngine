export module ZEngine.Core.IInitializable;

import std;

export namespace ZEngine::Core
{

    struct IInitializable
    {
        IInitializable()          = default;
        virtual ~IInitializable() = default;

        virtual void Initialize() = 0;
        virtual void Deinitialize() {}
    };
} // namespace ZEngine::Core
