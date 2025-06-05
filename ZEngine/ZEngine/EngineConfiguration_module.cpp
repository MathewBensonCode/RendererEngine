export module ZEngine.EngineConfiguration;

import std;
import ZEngine.Logging.LoggerConfiguration;
import ZEngine.Windows.WindowConfiguration;

export namespace ZEngine
{

    struct EngineConfiguration
    {
        Logging::LoggerConfiguration LoggerConfiguration;
        Windows::WindowConfiguration WindowConfiguration;
    };

} // namespace ZEngine
