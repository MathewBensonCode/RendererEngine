export module ZEngine.Rendering:Geometries.SquareGeometry;

import :Geometries.IGeometry;

namespace ZEngine::Rendering::Renderers::Storages
{
    struct GraphicVertex;
}

namespace ZEngine::Rendering::Geometries
{

    export struct SquareGeometry : public IGeometry
    {
        SquareGeometry();
        ~SquareGeometry() = default;
    };

    SquareGeometry::SquareGeometry() : IGeometry({Renderers::Storages::GraphicVertex({-0.5f, -0.5f, 1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}), Renderers::Storages::GraphicVertex({0.5f, -0.5f, 1.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f}), Renderers::Storages::GraphicVertex({0.0f, 0.5f, 1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f}), Renderers::Storages::GraphicVertex({0.5f, -0.5f, 1.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f})}) {}
} // namespace ZEngine::Rendering::Geometries
