export module ZEngine.Logging.LoggerConfiguration;

import std;

export namespace ZEngine::Logging
{
    struct LoggerConfiguration
    {
        std::string               EngineLoggerName = "ENGINE";
        std::string               OutputDirectory  = "Logs";
        std::string               LogFilename      = "engine_dump.log";
        std::chrono::milliseconds PeriodicFlush    = std::chrono::milliseconds(1);
    };
} // namespace ZEngine::Logging
