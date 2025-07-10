module;
#include <yaml-cpp/yaml.h>

export module ZEngine.Rendering:Serializers.GraphicScene3DSerializer;

import std;
import :Entities.GraphicSceneEntity;
import ZEngine.Maths.Math;
import :Serializers.GraphicSceneSerializer;
import ZEngine.ZEngineDef;

export namespace ZEngine::Rendering::Serializers
{

    YAML::Emitter& operator<<(YAML::Emitter& emitter, const ZEngine::Maths::Vector4& v)
    {
        emitter << YAML::Flow;
        emitter << YAML::BeginSeq << v.x << v.y << v.z << v.w << YAML::EndSeq;
        return emitter;
    }

    YAML::Emitter& operator<<(YAML::Emitter& emitter, const ZEngine::Maths::Vector3& v)
    {
        emitter << YAML::Flow;
        emitter << YAML::BeginSeq << v.x << v.y << v.z << YAML::EndSeq;
        return emitter;
    }

    YAML::Emitter& operator<<(YAML::Emitter& emitter, const ZEngine::Maths::Vector2& v)
    {
        emitter << YAML::Flow;
        emitter << YAML::BeginSeq << v.x << v.y << YAML::EndSeq;
        return emitter;
    }

    class GraphicScene3DSerializer : public GraphicSceneSerializer
    {
    public:
        GraphicScene3DSerializer(const Helpers::Ref<ZEngine::Rendering::Scenes::GraphicScene>& scene);
        virtual ~GraphicScene3DSerializer() = default;

        Core::SerializeInformation Serialize(std::string_view filename) override;
        Core::SerializeInformation Deserialize(std::string_view filename) override;

    private:
        void SerializeSceneEntity(YAML::Emitter& emitter, const ZEngine::Rendering::Entities::GraphicSceneEntity& entity);

        template <typename T>
        void SerializeSceneEntityComponent(YAML::Emitter& emitter, const ZEngine::Rendering::Entities::GraphicSceneEntity& entity, std::function<void(YAML::Emitter&, T&)> serialize_function)
        {
            if (entity.HasComponent<T>())
            {
                auto& component = entity.GetComponent<T>();
                serialize_function(emitter, component);
            }
        }
    };
} // namespace ZEngine::Serializers
