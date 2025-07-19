module;
#include <assimp/matrix4x4.h>
#include <glm/glm.hpp>

export module ZEngine.Helpers.MathHelper;

export namespace ZEngine::Helpers
{

    glm::mat4 ConvertToMat4(const aiMatrix4x4& m)
    {
        glm::mat4 mm;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                mm[i][j] = m[i][j];
            }
        }
        return mm;
    }
} // namespace ZEngine::Helpers
