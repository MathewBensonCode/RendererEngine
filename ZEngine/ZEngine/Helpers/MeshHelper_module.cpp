module;
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

export module ZEngine.Helpers.MeshHelper;

import std;
import ZEngine.Rendering;

export namespace ZEngine::Helpers
{
    Rendering::Meshes::MeshVNext CreateBuiltInMesh(Rendering::Meshes::MeshType mesh_type)
    {
        Rendering::Meshes::MeshVNext custom_mesh = {};
        return custom_mesh;
    }

    bool ExtractMeshFromAssimpSceneNode(aiNode* const root_node, std::vector<uint32_t>* const mesh_id_collection_ptr)
    {
        if (!root_node || !mesh_id_collection_ptr)
        {
            return false;
        }

        for (int i = 0; i < root_node->mNumMeshes; ++i)
        {
            mesh_id_collection_ptr->push_back(root_node->mMeshes[i]);
        }

        if (root_node->mNumChildren > 0)
        {
            for (int i = 0; i < root_node->mNumChildren; ++i)
            {
                ExtractMeshFromAssimpSceneNode(root_node->mChildren[i], mesh_id_collection_ptr);
            }
        }

        return true;
    }

    std::vector<Rendering::Meshes::MeshVNext> ConvertAssimpMeshToZEngineMeshModel(const aiScene* assimp_scene, const std::vector<uint32_t>& assimp_mesh_ids);
} // namespace ZEngine::Helpers
