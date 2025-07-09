export module ZEngine.Logging:LoggerDefinition;

import std;
import :Logger;

export template<typename ...args>
auto ZENGINE_CORE_INFO(args ...myargs){ 
    ZEngine::Logging::Logger::Info(std::format(myargs...));
}

export template<typename ...args>
auto ZENGINE_CORE_TRACE(args ...myargs){ 
    ZEngine::Logging::Logger::Trace(std::format(myargs...));
}

export template<typename ...args>
auto ZENGINE_CORE_WARN(args ...myargs){ 
    ZEngine::Logging::Logger::Warn(std::format(myargs...));
}


export template<typename ...args>
auto ZENGINE_CORE_ERROR(args ...myargs){ 
    ZEngine::Logging::Logger::Error(std::format(myargs...));
}

export template<typename ...args>
auto ZENGINE_CORE_CRITICAL(args ...myargs){ 
    ZEngine::Logging::Logger::Critical(std::format(myargs...));
}
