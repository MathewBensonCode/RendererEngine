module;
#define INVALID_MAP_HANDLE 0xFFFFFFFFu

export module ZEngine.Rendering:Meshes.Mesh;

import std;
import :GPUTypes;
import ZEngine.ZEngineDef;

export namespace ZEngine::Rendering::Meshes
{

    enum class MeshType
    {
        CUSTOM = 0,
        CUBE   = 1,
        QUAD   = 2,
        SQUARE = 3
    };

    struct MeshVNext
    {
        std::uint32_t VertexCount          = 0;
        std::uint32_t IndexCount           = 0;
        std::uint32_t VertexOffset         = 0;
        std::uint32_t IndexOffset          = 0;
        std::uint32_t StreamOffset         = 0;
        std::uint32_t IndexStreamOffset    = 0;
        std::uint32_t VertexUnitStreamSize = 0;
        std::uint32_t IndexUnitStreamSize  = 0;
        std::uint32_t TotalByteSize        = 0;
    };

    struct Mesh : public MeshVNext
    {
        bool m_is_MeshLight_mesh_object;
    };

    struct MeshMaterial
    {
        gpuvec4       AmbientColor   = 1.0f;
        gpuvec4       EmissiveColor  = 0.0f;
        gpuvec4       AlbedoColor    = 1.0f;
        gpuvec4       SpecularColor  = 1.0f;
        gpuvec4       RoughnessColor = 1.0f;
        gpuvec4       Factors        = 1.0f; // {x : transparency, y : Metallic, z : AlphaTest, w : _padding}
        std::uint64_t EmissiveMap    = INVALID_MAP_HANDLE;
        std::uint64_t AlbedoMap      = INVALID_MAP_HANDLE;
        std::uint64_t SpecularMap    = INVALID_MAP_HANDLE;
        std::uint64_t NormalMap      = INVALID_MAP_HANDLE;
        std::uint64_t OpacityMap     = INVALID_MAP_HANDLE;
        std::uint64_t _padding       = INVALID_MAP_HANDLE;
    };

    struct MaterialFile
    {
        char AlbedoTexture[MAX_FILE_PATH_COUNT]   = {0};
        char EmissiveTexture[MAX_FILE_PATH_COUNT] = {0};
        char NormalTexture[MAX_FILE_PATH_COUNT]   = {0};
        char OpacityTexture[MAX_FILE_PATH_COUNT]  = {0};
        char SpecularTexture[MAX_FILE_PATH_COUNT] = {0};
    };
} // namespace ZEngine::Rendering::Meshes
