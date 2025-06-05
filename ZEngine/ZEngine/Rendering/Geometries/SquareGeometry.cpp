module ZEngine.Rendering.Geometries.SquareGeometry;

import ZEngine.Rendering.Renderers.Storages.GraphicVertex;

namespace ZEngine::Rendering::Geometries
{
    SquareGeometry::SquareGeometry() : IGeometry({Renderers::Storages::GraphicVertex({-0.5f, -0.5f, 1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}), Renderers::Storages::GraphicVertex({0.5f, -0.5f, 1.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f}), Renderers::Storages::GraphicVertex({0.0f, 0.5f, 1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f}), Renderers::Storages::GraphicVertex({0.5f, -0.5f, 1.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f})}) {}
} // namespace ZEngine::Rendering::Geometries
