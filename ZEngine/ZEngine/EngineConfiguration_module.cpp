export module ZEngine.EngineConfiguration;

import std;
import ZEngine.Logging;
import ZEngine.Windows;

export namespace ZEngine
{
    struct EngineConfiguration
    {
        Logging::LoggerConfiguration LoggerConfiguration;
        Windows::WindowConfiguration WindowConfiguration;
    };

} // namespace ZEngine
