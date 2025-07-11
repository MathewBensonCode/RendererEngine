export module ZEngine.Rendering:Windows.WindowConfiguration;

import std;
import :Windows.Layers;
import ZEngine.Core.Containers.Array;
import ZEngine.Core.Containers.Strings;
import ZEngine.Helpers.IntrusivePtr;

export namespace ZEngine::Rendering::Windows
{
    struct WindowConfiguration
    {
        std::uint32_t                                        Width       = 1500;
        std::uint32_t                                        Height      = 800;
        bool                                            EnableVsync = true;
        Core::Containers::String                        Title;

        Core::Containers::Array<Layer*> RenderingLayerCollection;
        Core::Containers::Array<Layer*> OverlayLayerCollection;
    };

} // namespace ZEngine::Windows
