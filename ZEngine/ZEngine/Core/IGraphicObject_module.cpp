module;

#include <cstdint>

export module ZEngine.Core.IGraphicObject;

import std;

export namespace ZEngine::Core
{
    struct IGraphicObject
    {
        IGraphicObject()                            = default;
        virtual ~IGraphicObject()                   = default;
        virtual std::uint32_t GetIdentifier() const = 0;
    };
} // namespace ZEngine::Core
