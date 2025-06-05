export module ZEngine.Serializers.GraphicSceneSerializer;

import std;
import ZEngine.Core.ISerializer;
import ZEngine.Rendering.Scenes.GraphicScene;
import ZEngine.ZEngineDef;


namespace ZEngine::Serializers
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
