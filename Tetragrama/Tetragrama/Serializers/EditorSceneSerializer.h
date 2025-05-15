#pragma once
#include <Tetragrama/Editor.h>
#include <Tetragrama/Serializers/Serializer.h>
#include <span>

namespace Tetragrama::Serializers
{
    class EditorSceneSerializer : public Serializer<EditorScene>
    {
    public:
        virtual void Serialize(const ZEngine::Ref<EditorScene>& data) override;
        virtual void Deserialize(std::string_view filename) override;
    };
} // namespace Tetragrama::Serializers
