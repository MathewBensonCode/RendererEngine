module;

export module ZEngine.Rendering.Geometries.SquareGeometry;

import std;

import ZEngine.Rendering.Geometries.IGeometry;

export namespace ZEngine::Rendering::Geometries
{

    struct SquareGeometry : public IGeometry
    {
        SquareGeometry();
        ~SquareGeometry() = default;
    };
} // namespace ZEngine::Rendering::Geometries
