module;

export module ZEngine.Rendering.Geometries.CubeGeometry;

import std;

import ZEngine.Rendering.Geometries.IGeometry;

export namespace ZEngine::Rendering::Geometries
{

    struct CubeGeometry : public IGeometry
    {
        CubeGeometry();
        ~CubeGeometry() = default;
    };
} // namespace ZEngine::Rendering::Geometries
