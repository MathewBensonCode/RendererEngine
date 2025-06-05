module;
export module ZEngine.Logging.LoggerDefinition;

import std;
import fmt;
import ZEngine.Logging.Logger;

export template<typename ...args>
auto ZENGINE_CORE_INFO(args ...myargs){ 
    ZEngine::Logging::Logger::Info(fmt::format(myargs...));
}

export template<typename ...args>
auto ZENGINE_CORE_TRACE(args ...myargs){ 
    ZEngine::Logging::Logger::Trace(fmt::format(myargs...));
}

export template<typename ...args>
auto ZENGINE_CORE_WARN(args ...myargs){ 
    ZEngine::Logging::Logger::Warn(fmt::format(myargs...));
}


export template<typename ...args>
auto ZENGINE_CORE_ERROR(args ...myargs){ 
    ZEngine::Logging::Logger::Error(fmt::format(myargs...));
}

export template<typename ...args>
auto ZENGINE_CORE_CRITICAL(args ...myargs){ 
    ZEngine::Logging::Logger::Critical(fmt::format(myargs...));
}
