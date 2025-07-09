export module ZEngine.Rendering:Geometries.QuadGeometry;

import :Geometries.IGeometry;

namespace ZEngine::Rendering::Renderers::Storages{
    struct GraphicVertex;
}

namespace ZEngine::Rendering::Geometries
{
    export struct QuadGeometry : public IGeometry
    {
        QuadGeometry();
        ~QuadGeometry() = default;
    };

    QuadGeometry::QuadGeometry() : IGeometry({Renderers::Storages::GraphicVertex({-0.75f, -0.5f, 1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}), Renderers::Storages::GraphicVertex({0.75f, -0.5f, 1.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f}), Renderers::Storages::GraphicVertex({0.75f, 0.5f, 1.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f}), Renderers::Storages::GraphicVertex({-0.75f, 0.5f, 1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f})}) {}
} // namespace ZEngine::Rendering::Geometries
