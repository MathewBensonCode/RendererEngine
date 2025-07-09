export module ZEngine.Rendering:IRenderable;

import std;

namespace ZEngine::Rendering::Devices{
    struct CommandBuffer;
}

namespace ZEngine::Rendering::Renderers{
    struct GraphicRenderer;
}


namespace ZEngine::Rendering
{

    export struct IRenderable
    {
        IRenderable()                                                                                                                                  = default;
        virtual ~IRenderable()                                                                                                                         = default;

        virtual void Render(Rendering::Renderers::GraphicRenderer* const renderer = nullptr, Devices::CommandBuffer* const command_buffer = nullptr) = 0;
    };
} // namespace ZEngine::Core
