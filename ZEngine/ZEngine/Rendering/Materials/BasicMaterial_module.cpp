export module ZEngine.Rendering.Materials.BasicMaterial;

import std;
import ZEngine.Rendering.Materials.ShaderMaterial;
import ZEngine.Rendering.Textures.Texture;

export namespace ZEngine::Rendering::Materials
{

    class BasicMaterial : public ShaderMaterial
    {
    public:
        explicit BasicMaterial();
        virtual ~BasicMaterial() = default;

        void               SetTexture(const Textures::Texture*);
        Textures::Texture* GetTexture() const;

        void               Apply(const Helpers::Ref<Shaders::Shader>&) override;

    private:
        Textures::Texture* m_texture;
    };
} // namespace ZEngine::Rendering::Materials
