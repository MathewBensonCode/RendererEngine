module ZEngine.Helpers.ThreadPool;

import ZEngine.Helpers.IntrusivePtr;

namespace ZEngine::Helpers
{
    Scope<ThreadPool> ThreadPoolHelper::m_threadPool = CreateScope<ThreadPool>();
}
