export module ZEngine.Core.Memory.MemoryManager;

import std;
import ZEngine.Core.Memory.Allocator;
import ZEngine.ZEngineDef;

export namespace ZEngine::Core::Memory
{
    struct MemoryConfiguration
    {
        std::uint64_t DefaultSize = ZGiga(2ull);
    };

    struct MemoryManager
    {
        void Initialize(const MemoryConfiguration& config)
        {
            m_ArenaAllocator.Initialize(config.DefaultSize);
        }

        void Shutdowm()
        {
            m_ArenaAllocator.Shutdown();
        }

        ArenaAllocator m_ArenaAllocator = {};
    };
} // namespace ZEngine::Core::Memory
