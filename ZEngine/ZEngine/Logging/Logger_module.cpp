module;
#include <spdlog/sinks/base_sink.h>
#include <spdlog/spdlog.h>

export module ZEngine.Logging.Logger;

import std;
import ZEngine.Logging.LoggerConfiguration;

export namespace ZEngine::Logging
{
    struct LogMessage
    {
        float       Color[4] = {0.0f};
        std::string Message{};
    };

    struct Logger
    {
        using LogEventHandler = std::function<void(LogMessage)>;

        static void     Initialize(void* arena, const LoggerConfiguration&);
        static void     Flush();
        static void     Dispose();
        static std::uint32_t AddEventHandler(LogEventHandler handler);
        static void     RemoveEventHandler(std::uint32_t cookie);

        static void     Info(std::string msg);
        static void     Trace(std::string msg);
        static void     Warn(std::string msg);
        static void     Error(std::string msg);
        static void     Critical(std::string msg);

    private:
        Logger()              = delete;
        Logger(const Logger&) = delete;
    };
} // namespace ZEngine::Logging
