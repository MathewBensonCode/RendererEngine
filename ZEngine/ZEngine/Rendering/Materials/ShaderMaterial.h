#pragma once
#include <ZEngine/Rendering/Materials/IMaterial.h>
#include <ZEngine/Rendering/Shaders/Shader.h>
#include <ZEngine/Rendering/Shaders/ShaderEnums.h>

namespace ZEngine::Rendering::Materials
{

    class ShaderMaterial : public IMaterial
    {
    public:
        explicit ShaderMaterial(Shaders::ShaderBuiltInType type);

        virtual ~ShaderMaterial() = default;

        virtual void Apply(const Ref<Shaders::Shader>&);
    };
} // namespace ZEngine::Rendering::Materials
