export module ZEngine.Rendering:Geometries.GeometryEnum;

import std;

export namespace ZEngine::Rendering::Geometries
{
    enum class GeometryType
    {
        CUSTOM = 0,
        CUBE   = 1,
        QUAD   = 2,
        SQUARE = 3
    };
} // namespace ZEngine::Rendering::Geometries
