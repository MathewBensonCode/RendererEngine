export module ZEngine.EngineConfiguration;

import std;
import ZEngine.Logging;
import ZEngine.Rendering;

export namespace ZEngine
{
    struct EngineConfiguration
    {
        Logging::LoggerConfiguration            LoggerConfiguration;
        Rendering::Windows::WindowConfiguration WindowConfiguration;
    };

} // namespace ZEngine
