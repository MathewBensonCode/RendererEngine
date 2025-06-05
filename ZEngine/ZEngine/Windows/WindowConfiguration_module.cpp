export module ZEngine.Windows.WindowConfiguration;

import std;
import ZEngine.Core.Containers.Array;
import ZEngine.Core.Containers.Strings;
import ZEngine.Helpers.IntrusivePtr;

namespace ZEngine::Windows::Layers
{
    class Layer;
}

export namespace ZEngine::Windows
{
    struct WindowConfiguration
    {
        std::uint32_t                                        Width       = 1500;
        std::uint32_t                                        Height      = 800;
        bool                                            EnableVsync = true;
        Core::Containers::String                        Title;

        Core::Containers::Array<Layers::Layer*> RenderingLayerCollection;
        Core::Containers::Array<Layers::Layer*> OverlayLayerCollection;
    };

} // namespace ZEngine::Windows
