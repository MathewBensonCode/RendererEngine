export module ZEngine.Rendering:Serializers.GraphicSceneSerializer;

import std;
import ZEngine.Core.ISerializer;
import ZEngine.ZEngineDef;
import :Scenes.GraphicScene;


namespace ZEngine::Rendering::Serializers
{
    struct GraphicSceneSerializer : public Core::ISerializer
    {
        GraphicSceneSerializer()          = default;
        virtual ~GraphicSceneSerializer() = default;

    protected:
        std::filesystem::path                                      m_default_scene_directory_path;
        Helpers::WeakRef<ZEngine::Rendering::Scenes::GraphicScene> m_scene;
    };
} // namespace ZEngine::Serializers
