module ZEngine.Rendering.Materials.ShaderMaterial;

import ZEngine.Helpers.IntrusivePtr;

using namespace ZEngine::Helpers;

namespace ZEngine::Rendering::Materials
{

    ShaderMaterial::ShaderMaterial(Shaders::ShaderBuiltInType type) : IMaterial()
    {
        m_shader_built_in_type = type;
    }

    void ShaderMaterial::Apply(const Ref<Shaders::Shader>& shader)
    {
        assert(shader != nullptr);

        // shader->Bind();
    }
} // namespace ZEngine::Rendering::Materials
