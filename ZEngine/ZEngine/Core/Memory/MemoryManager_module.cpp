#pragma once
#include <ZEngine/Core/Memory/Allocator.h>

namespace ZEngine::Core::Memory
{
    struct MemoryConfiguration
    {
        uint64_t DefaultSize = ZGiga(2ull);
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
