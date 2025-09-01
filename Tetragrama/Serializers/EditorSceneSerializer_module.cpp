import Tetragrama.Editor;
import Tetragrama.Importers.IAssetImporter;
import Tetragrama.Serializers.Serializer;

namespace Tetragrama::Serializers
{
    struct EditorSceneSerializer : public Serializer<EditorScene>
    {
        virtual void Serialize(ZRawPtr(EditorScene) const data) override;
        virtual void Deserialize(std::string_view filename) override;
    };
} // namespace Tetragrama::Serializers
