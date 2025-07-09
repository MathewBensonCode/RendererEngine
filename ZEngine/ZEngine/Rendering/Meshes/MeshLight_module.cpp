export module ZEngine.Rendering:Meshes.MeshLight;

import std;
import :Lights.Light;
import :Meshes.Mesh;
import :Geometries.IGeometry;
import :Materials.ShaderMaterial;
import ZEngine.Helpers.IntrusivePtr;
import ZEngine.Maths.Math;

export namespace ZEngine::Rendering::Mesh
{

    struct MeshLight : public Meshes::Mesh
    {
        explicit MeshLight() : Mesh()
        {
            m_is_MeshLight_mesh_object = true;
        }

        explicit MeshLight(Helpers::Ref<Geometries::IGeometry>&& geometry, Helpers::Ref<Materials::ShaderMaterial>&& material) : Mesh(geometry, material) {}
        explicit MeshLight(Helpers::Ref<Geometries::IGeometry>& geometry, Helpers::Ref<Materials::ShaderMaterial>& material) : Mesh(geometry, material) {}
        explicit MeshLight(Geometries::IGeometry* const geometry, Materials::ShaderMaterial* const material) : Mesh(geometry, material) {}

        virtual ~MeshLight() = default;

        void                SetLight(const Lights::LightVNext&);
        Lights::LightVNext& GetLight();

    private:
        Lights::LightVNext m_basic_light;
    };
} // namespace ZEngine::Rendering::Mesh
