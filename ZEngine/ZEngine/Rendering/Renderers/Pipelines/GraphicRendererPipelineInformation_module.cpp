export module ZEngine.Rendering.Renderers.Pipelines.GraphicRendererPipelineInformation;

import std;
import ZEngine.Rendering.Geometries.IGeometry;
import ZEngine.Rendering.Materials.ShaderMaterial;
import ZEngine.Rendering.Meshes.Mesh;
import ZEngine.Rendering.Shaders.ShaderEnums;
import ZEngine.ZEngineDef;

export namespace ZEngine::Rendering::Renderers
{

    struct GraphicRendererInformationRecord
    {
        std::uint32_t ShaderIndex{0};
        std::uint32_t GeometryIndex{0};
        std::uint32_t MaterialIndex{0};
    };

    struct GraphicRendererPipelineInformation
    {
        bool                                                 IsPipelineStatesInitialized{false};

        std::uint32_t                                             DesiredWidth{1};
        std::uint32_t                                             DesiredHeight{1};

        std::uint32_t                                             GeometryCollectionCount{0};
        std::uint32_t                                             MaterialCollectionCount{0};

        std::vector<Rendering::Meshes::Mesh>                 MeshCollection;
        std::vector<Helpers::Ref<Geometries::IGeometry>>     GeometryCollection;
        std::vector<Helpers::Ref<Materials::ShaderMaterial>> MaterialCollection;
        std::vector<GraphicRendererInformationRecord>        RecordCollection;
    };
} // namespace ZEngine::Rendering::Renderers
