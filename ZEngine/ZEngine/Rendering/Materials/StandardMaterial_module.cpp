module;
#include <glm/glm.hpp>

export module ZEngine.Rendering:Materials.StandardMaterial;

import std;
import ZEngine.Maths.Math;
import :Lights.Light;
import :Materials.ShaderMaterial;

export namespace ZEngine::Rendering::Materials
{

    class StandardMaterial : public ShaderMaterial
    {
    public:
        explicit StandardMaterial();
        virtual ~StandardMaterial() = default;

        void                  SetTileFactor(float value);
        void                  SetDiffuseTintColor(const glm::vec4& value);
        void                  SetSpecularTintColor(const glm::vec4& value);

        void                  SetShininess(float value);

        void                  Apply(const Helpers::Ref<Shaders::Shader>&) override;

        void                  SetSpecularMap(const Textures::Texture* texture);
        void                  SetDiffuseMap(const Textures::Texture* texture);

        float                 GetTileFactor() const;
        float                 GetShininess() const;
        const Maths::Vector4& GetDiffuseTintColor() const;
        const Maths::Vector4& GetSpecularTintColor() const;

        Textures::Texture*    GetSpecularMap() const;
        Textures::Texture*    GetDiffuseMap() const;

    private:
        float              m_shininess;
        float              m_tile_factor;
        Maths::Vector4     m_diffuse_tint_color;
        Maths::Vector4     m_specular_tint_color;
        Textures::Texture* m_diffuse_map;
        Textures::Texture* m_specular_map;
    };

    StandardMaterial::StandardMaterial() : ShaderMaterial(Shaders::ShaderBuiltInType::STANDARD), m_tile_factor(1.0f), m_diffuse_tint_color(glm::vec4(1.0f)), m_specular_tint_color(glm::vec4(1.0f)), m_diffuse_map(Textures::CreateTexture(1, 1)), m_specular_map(Textures::CreateTexture(1, 1))
    {
        m_material_name = typeid(*this).name();
    }

    void StandardMaterial::SetTileFactor(float value)
    {
        m_tile_factor = value;
    }

    void StandardMaterial::SetDiffuseTintColor(const glm::vec4& value)
    {
        m_diffuse_tint_color = value;
    }

    void StandardMaterial::SetSpecularTintColor(const glm::vec4& value)
    {
        m_specular_tint_color = value;
    }

    void StandardMaterial::SetShininess(float value)
    {
        m_shininess = value;
    }

    void StandardMaterial::SetSpecularMap(const Textures::Texture* texture)
    {
        // m_specular_map = texture;
    }

    void StandardMaterial::SetDiffuseMap(const Textures::Texture* texture)
    {
        // m_diffuse_map = texture;
    }

    float StandardMaterial::GetTileFactor() const
    {
        return m_tile_factor;
    }

    float StandardMaterial::GetShininess() const
    {
        return m_shininess;
    }

    const Maths::Vector4& StandardMaterial::GetDiffuseTintColor() const
    {
        return m_diffuse_tint_color;
    }

    const Maths::Vector4& StandardMaterial::GetSpecularTintColor() const
    {
        return m_specular_tint_color;
    }

    Textures::Texture* StandardMaterial::GetSpecularMap() const
    {
        return m_specular_map;
    }

    Textures::Texture* StandardMaterial::GetDiffuseMap() const
    {
        return m_diffuse_map;
    }

    void StandardMaterial::Apply(const Ref<Shaders::Shader>& shader)
    {
        // ShaderMaterial::Apply(shader);

        // shader->SetUniform("Material.TilingFactor", m_tile_factor);
        // shader->SetUniform("Material.Shininess", m_shininess);
        // shader->SetUniform("Material.DiffuseTintColor", m_diffuse_tint_color);
        // shader->SetUniform("Material.SpecularTintColor", m_specular_tint_color);

        // shader->SetUniform("Material.Diffuse", 0);
        // shader->SetUniform("Material.Specular", 1);

        // m_diffuse_map->Bind();
        // m_specular_map->Bind(1);
    }
} // namespace ZEngine::Rendering::Materials
