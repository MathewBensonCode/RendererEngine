#include <ZEngine/Helpers/ThreadPool.h>
#include <memory>

namespace ZEngine::Helpers
{
    std::unique_ptr<ThreadPool> ThreadPoolHelper::m_threadPool = std::make_unique<ThreadPool>();
}
