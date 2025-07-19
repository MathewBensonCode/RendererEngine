export module ZEngine.Rendering:Materials.BasicMaterial;

import std;
import :Materials.ShaderMaterial;
import :Textures.Texture;

namespace ZEngine::Rendering::Materials
{

    export class BasicMaterial : public ShaderMaterial
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

    BasicMaterial::BasicMaterial() : ShaderMaterial(Shaders::ShaderBuiltInType::BASIC)
    {
        m_material_name = typeid(*this).name();
        // m_texture.reset(Textures::CreateTexture(1, 1));
    }

    void BasicMaterial::SetTexture(const Textures::Texture* texture)
    {
        // m_texture = texture;
    }

    Textures::Texture* BasicMaterial::GetTexture() const
    {
        return m_texture;
    }

    void BasicMaterial::Apply(const Helpers::Ref<Shaders::Shader>& shader)
    {
        // ShaderMaterial::Apply(shader);
        // m_texture->Bind();
    }
} // namespace ZEngine::Rendering::Materials
