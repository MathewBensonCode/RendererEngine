#pragma once
#include <Tetragrama/Components/DemoUIComponent.h>
#include <Tetragrama/Components/DockspaceUIComponent.h>
#include <Tetragrama/Components/HierarchyViewUIComponent.h>
#include <Tetragrama/Components/InspectorViewUIComponent.h>
#include <Tetragrama/Components/LogUIComponent.h>
#include <Tetragrama/Components/ProjectViewUIComponent.h>
#include <Tetragrama/Components/SceneViewportUIComponent.h>
#include <ZEngine/ZEngine.h>

namespace Tetragrama::Layers
{
    class UILayer : public ZEngine::Layers::ImguiLayer
    {
    public:
        UILayer(std::string_view name = "user interface layer") : ImguiLayer(name.data()) {}

        virtual ~UILayer();

        void Initialize() override;

    private:
        ZEngine::Ref<Components::DockspaceUIComponent>     m_dockspace_component;
        ZEngine::Ref<Components::SceneViewportUIComponent> m_scene_component;
        ZEngine::Ref<Components::LogUIComponent>           m_editor_log_component;
        ZEngine::Ref<Components::DemoUIComponent>          m_demo_component;
        ZEngine::Ref<Components::ProjectViewUIComponent>   m_project_view_component;
        ZEngine::Ref<Components::InspectorViewUIComponent> m_inspector_view_component;
        ZEngine::Ref<Components::HierarchyViewUIComponent> m_hierarchy_view_component;
    };

} // namespace Tetragrama::Layers
