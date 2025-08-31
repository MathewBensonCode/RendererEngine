#pragma once
#include <Tetragrama/Editor.h>
#include <Tetragrama/Importers/IAssetImporter.h>
#include <Tetragrama/Serializers/Serializer.h>

namespace Tetragrama::Serializers
{
    struct EditorSceneSerializer : public Serializer<EditorScene>
    {
        virtual void Serialize(ZRawPtr(EditorScene) const data) override;
        virtual void Deserialize(std::string_view filename) override;
    };
} // namespace Tetragrama::Serializers
