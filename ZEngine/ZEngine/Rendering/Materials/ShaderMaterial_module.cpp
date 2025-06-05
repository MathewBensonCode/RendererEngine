export module ZEngine.Rendering.Materials.ShaderMaterial;

import ZEngine.Rendering.Materials.IMaterial;
import ZEngine.Rendering.Shaders.Shader;
import ZEngine.Helpers.IntrusivePtr;

export namespace ZEngine::Rendering::Materials
{

    class ShaderMaterial : public IMaterial
    {
    public:
        explicit ShaderMaterial(Shaders::ShaderBuiltInType type);

        virtual ~ShaderMaterial() = default;

        virtual void Apply(const Helpers::Ref<Shaders::Shader>&);
    };
} // namespace ZEngine::Rendering::Materials
