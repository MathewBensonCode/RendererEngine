export module ZEngine.Rendering:Geometries.CubeGeometry;

import std;
import :Geometries.IGeometry;

namespace ZEngine::Rendering::Renderers::Storages
{
    struct GraphicVertex;
}

namespace ZEngine::Rendering::Geometries
{

    export struct CubeGeometry : public IGeometry
    {
        CubeGeometry();
        ~CubeGeometry() = default;
    };

    CubeGeometry::CubeGeometry()
        : IGeometry({
          Renderers::Storages::GraphicVertex({-0.75f, -0.75f, -0.75f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}), Renderers::Storages::GraphicVertex({0.75f, -0.75f, -0.75f}, {0.0f, 0.0f, -1.0f}, {1.0f, 0.0f}), Renderers::Storages::GraphicVertex({0.75f, 0.75f, -0.75f}, {0.0f, 0.0f, -1.0f}, {1.0f, 1.0f}),
          Renderers::Storages::GraphicVertex({0.75f, 0.75f, -0.75f}, {0.0f, 0.0f, -1.0f}, {1.0f, 1.0f}),   Renderers::Storages::GraphicVertex({-0.75f, 0.75f, -0.75f}, {0.0f, 0.0f, -1.0f}, {0.0f, 1.0f}), Renderers::Storages::GraphicVertex({-0.75f, -0.75f, -0.75f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}),

          Renderers::Storages::GraphicVertex({-0.75f, -0.75f, 0.75f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}),   Renderers::Storages::GraphicVertex({0.75f, -0.75f, 0.75f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}),   Renderers::Storages::GraphicVertex({0.75f, 0.75f, 0.75f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}),
          Renderers::Storages::GraphicVertex({0.75f, 0.75f, 0.75f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}),     Renderers::Storages::GraphicVertex({-0.75f, 0.75f, 0.75f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}),   Renderers::Storages::GraphicVertex({-0.75f, -0.75f, 0.75f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}),

          Renderers::Storages::GraphicVertex({-0.75f, 0.75f, 0.75f}, {-1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}),   Renderers::Storages::GraphicVertex({-0.75f, 0.75f, -0.75f}, {-1.0f, 0.0f, 0.0f}, {1.0f, 1.0f}), Renderers::Storages::GraphicVertex({-0.75f, -0.75f, -0.75f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 1.0f}),
          Renderers::Storages::GraphicVertex({-0.75f, -0.75f, -0.75f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 1.0f}), Renderers::Storages::GraphicVertex({-0.75f, -0.75f, 0.75f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}), Renderers::Storages::GraphicVertex({-0.75f, 0.75f, 0.75f}, {-1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}),

          Renderers::Storages::GraphicVertex({0.75f, 0.75f, 0.75f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}),     Renderers::Storages::GraphicVertex({0.75f, 0.75f, -0.75f}, {1.0f, 0.0f, 0.0f}, {1.0f, 1.0f}),   Renderers::Storages::GraphicVertex({0.75f, -0.75f, -0.75f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f}),
          Renderers::Storages::GraphicVertex({0.75f, -0.75f, -0.75f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f}),   Renderers::Storages::GraphicVertex({0.75f, -0.75f, 0.75f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}),   Renderers::Storages::GraphicVertex({0.75f, 0.75f, 0.75f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}),

          Renderers::Storages::GraphicVertex({-0.75f, -0.75f, -0.75f}, {0.0f, -1.0f, 0.0f}, {0.0f, 1.0f}), Renderers::Storages::GraphicVertex({0.75f, -0.75f, -0.75f}, {0.0f, -1.0f, 0.0f}, {1.0f, 1.0f}), Renderers::Storages::GraphicVertex({0.75f, -0.75f, 0.75f}, {0.0f, -1.0f, 0.0f}, {1.0f, 0.0f}),
          Renderers::Storages::GraphicVertex({0.75f, -0.75f, 0.75f}, {0.0f, -1.0f, 0.0f}, {1.0f, 0.0f}),   Renderers::Storages::GraphicVertex({-0.75f, -0.75f, 0.75f}, {0.0f, -1.0f, 0.0f}, {0.0f, 0.0f}), Renderers::Storages::GraphicVertex({-0.75f, -0.75f, -0.75f}, {0.0f, -1.0f, 0.0f}, {0.0f, 1.0f}),

          Renderers::Storages::GraphicVertex({-0.75f, 0.75f, -0.75f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f}),   Renderers::Storages::GraphicVertex({0.75f, 0.75f, -0.75f}, {0.0f, 1.0f, 0.0f}, {1.0f, 1.0f}),   Renderers::Storages::GraphicVertex({0.75f, 0.75f, 0.75f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}),
          Renderers::Storages::GraphicVertex({0.75f, 0.75f, 0.75f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}),     Renderers::Storages::GraphicVertex({-0.75f, 0.75f, 0.75f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}),   Renderers::Storages::GraphicVertex({-0.75f, 0.75f, -0.75f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f}),
          })
    {
        m_geometry_type = GeometryType::CUBE;
    }
} // namespace ZEngine::Rendering::Geometries
