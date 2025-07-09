import ZEngine.Core.Coroutine;
import ZEngine.Rendering;
import ZEngine.Helpers.MathHelper;
import ZEngine.Helpers.MeshHelper;
import ZEngine.ZEngineDef;

using namespace ZEngine::Rendering::Renderers;

namespace ZEngine::Helpers
{


    std::vector<Rendering::Meshes::MeshVNext> ConvertAssimpMeshToZEngineMeshModel(const aiScene* assimp_scene, const std::vector<uint32_t>& assimp_mesh_ids)
    {
        std::vector<Rendering::Meshes::MeshVNext> meshes = {};

        for (int i = 0; i < assimp_mesh_ids.size(); ++i)
        {
            aiMesh*               assimp_mesh = assimp_scene->mMeshes[assimp_mesh_ids[i]];

            std::uint32_t              vertex_count{0};
            std::vector<float>    vertices = {};
            std::vector<uint32_t> indices  = {};

            /* Vertice processing */
            for (int x = 0; x < assimp_mesh->mNumVertices; ++x)
            {
                vertices.push_back(assimp_mesh->mVertices[x].x);
                vertices.push_back(assimp_mesh->mVertices[x].y);
                vertices.push_back(assimp_mesh->mVertices[x].z);

                vertices.push_back(assimp_mesh->mNormals[x].x);
                vertices.push_back(assimp_mesh->mNormals[x].y);
                vertices.push_back(assimp_mesh->mNormals[x].z);

                if (assimp_mesh->mTextureCoords[0])
                {
                    vertices.push_back(assimp_mesh->mTextureCoords[0][x].x);
                    vertices.push_back(assimp_mesh->mTextureCoords[0][x].y);
                }
                else
                {
                    vertices.push_back(0.0f);
                    vertices.push_back(0.0f);
                }

                vertex_count++;
            }

            /* Face and Indices processing */
            for (int ix = 0; ix < assimp_mesh->mNumFaces; ++ix)
            {
                aiFace assimp_mesh_face = assimp_mesh->mFaces[ix];

                for (int j = 0; j < assimp_mesh_face.mNumIndices; ++j)
                {
                    indices.push_back(assimp_mesh_face.mIndices[j]);
                }
            }

            Rendering::Meshes::MeshVNext zengine_mesh = {};
            meshes.push_back(std::move(zengine_mesh));
        }

        return meshes;
    }

} // namespace ZEngine::Helpers
