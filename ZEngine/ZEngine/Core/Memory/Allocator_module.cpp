export module ZEngine.Core.Memory.Allocator;

import std;
import ZEngine.ZEngineDef;

export namespace ZEngine::Core::Memory
{
    struct ArenaAllocator;
    struct ArenaTemp;

    struct ArenaTemp
    {
        ArenaAllocator* Arena          = nullptr;
        std::size_t     CurrentOffset  = 0;
        std::size_t     PreviousOffset = 0;
    };

    struct ArenaAllocator
    {
        ~ArenaAllocator() {};

        void          Initialize(std::uint64_t size);
        void          Shutdown();

        void*         Allocate(std::size_t size, std::size_t alignment = DEFAULT_ALIGNMENT);
        void*         Allocate(std::size_t size, std::size_t alignment, const char* file, int line);

        void*         Resize(void* old_memory, std::size_t old_size, std::size_t new_size, std::size_t alignment = DEFAULT_ALIGNMENT);
        void          Clear();

        void          CreateSubArena(std::size_t size, ArenaAllocator* out_arena);

        std::uint8_t* m_memory                  = nullptr;
        std::size_t   m_total_size              = 0;
        std::size_t   m_initial_current_offset  = 0;
        std::size_t   m_initial_previous_offset = 0;
        std::size_t   m_current_offset          = 0;
        std::size_t   m_previous_offset         = 0;
    }; // struct ArenaAllocator

    struct PoolFreeNode
    {
        PoolFreeNode* Next = nullptr;
    };

    struct PoolAllocator
    {
        using Arena = ArenaAllocator;

        ~PoolAllocator() {};

        void          Initialize(Arena* arena, std::size_t size, std::size_t chunk_size, std::size_t alignment = DEFAULT_ALIGNMENT);

        void*         Allocate();
        void*         Allocate(const char* file, int line);

        void          Free(void* ptr);
        void          Clear();

        std::uint8_t* memory     = nullptr;
        PoolFreeNode* head       = nullptr;
        std::size_t   total_size = 0;
        std::size_t   chunk_size = 0;
    };

    ArenaTemp BeginTempArena(ArenaAllocator* arena);
    void      EndTempArena(ArenaTemp arena);
} // namespace ZEngine::Core::Memory

#define ZGetScratch(arena)       ZEngine::Core::Memory::BeginTempArena(arena)
#define ZReleaseScratch(scratch) ZEngine::Core::Memory::EndTempArena(scratch)
