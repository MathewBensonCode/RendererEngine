export module ZEngine.Rendering:Components.GeometryComponent;

import std;

export namespace ZEngine::Rendering::Components
{
    struct MeshComponent
    {
        MeshComponent(std::uint32_t mesh_id)
        {
            m_mesh_id = mesh_id;
        }

        std::uint32_t GetMeshID() const
        {
            return m_mesh_id;
        }

    private:
        std::uint32_t m_mesh_id{0xFFFFFFFF};
    };

} // namespace ZEngine::Rendering::Components
