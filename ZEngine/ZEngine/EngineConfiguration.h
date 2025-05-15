#pragma once
#include <ZEngine/Logging/LoggerConfiguration.h>
#include <ZEngine/Window/WindowConfiguration.h>

namespace ZEngine
{

    struct EngineConfiguration
    {
        Logging::LoggerConfiguration LoggerConfiguration;
        Window::WindowConfiguration  WindowConfiguration;
    };

} // namespace ZEngine
