#pragma once
#include <Core/Memory/Allocator.h>

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
            this->ArenaAllocatorValue.Initialize(config.DefaultSize);
        }

        void Shutdowm()
        {
            ArenaAllocatorValue.Shutdown();
        }

        ArenaAllocator ArenaAllocatorValue = {};
    };
} // namespace ZEngine::Core::Memory
