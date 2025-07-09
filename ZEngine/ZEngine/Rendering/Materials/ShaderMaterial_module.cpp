export module ZEngine.Rendering:Materials.ShaderMaterial;

import std;
import :Materials.IMaterial;
import :Shaders.Shader;
import ZEngine.Helpers.IntrusivePtr;

namespace ZEngine::Rendering::Materials
{

    export class ShaderMaterial : public IMaterial
    {
    public:
        explicit ShaderMaterial(Shaders::ShaderBuiltInType type);

        virtual ~ShaderMaterial() = default;

        virtual void Apply(const Helpers::Ref<Shaders::Shader>&);
    };

    ShaderMaterial::ShaderMaterial(Shaders::ShaderBuiltInType type) : IMaterial()
    {
        m_shader_built_in_type = type;
    }

    void ShaderMaterial::Apply(const Helpers::Ref<Shaders::Shader>& shader)
    {
       // assert(shader != nullptr);

        // shader->Bind();
    }
} // namespace ZEngine::Rendering::Materials
