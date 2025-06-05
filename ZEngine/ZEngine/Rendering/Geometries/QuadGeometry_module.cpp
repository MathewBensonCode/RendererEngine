module;

export module ZEngine.Rendering.Geometries.QuadGeometry;

import std;
import ZEngine.Rendering.Geometries.IGeometry;

export namespace ZEngine::Rendering::Geometries
{

    struct QuadGeometry : public IGeometry
    {
        QuadGeometry();
        ~QuadGeometry() = default;
    };
} // namespace ZEngine::Rendering::Geometries
