module;
#include <csignal>
#include <cassert>
#include <cstdlib>

#ifdef _MSC_VER
#define ZENGINE_DEBUG_BREAK() __debugbreak();
#elif defined(__APPLE__)
#define ZENGINE_DEBUG_BREAK() __builtin_trap();
#else
#define ZENGINE_DEBUG_BREAK() raise(SIGTRAP);
#endif

export module ZEngine.ZEngineDef;

import std;
import ZEngine.Logging.Logger;

export constexpr auto MAX_FILE_PATH_COUNT = 256;
export constexpr auto DEFAULT_STR_BUFFER  = 256;

export constexpr auto BIT(auto x)
{
    return (1 << (x));
}

export constexpr auto ZKilo(auto size)
{
    return size * 1024;
}
export constexpr auto ZMega(auto size)
{
    return ZKilo(size) * 1024;
}
export constexpr auto ZGiga(auto size)
{
    return ZMega(size) * 1024;
}

export constexpr auto DEFAULT_ALIGNMENT = (2 * sizeof(void*));

export constexpr auto* ZPush(auto* allocator, auto size, std::source_location location = std::source_location::current())
{
    return allocator->Allocate(size, DEFAULT_ALIGNMENT, location.file_name(), location.line());
}

<<<<<<< HEAD
=======
export template<typename type>
constexpr auto ZPushArray(auto* arena, auto count, std::source_location location = std::source_location::current())
{
    return ZPush(arena, (sizeof(type) * count), location);
}

export constexpr auto ZPushString(auto *arena, auto count)
{
    return ZPushArray<char>(arena, count);
}

export template<typename type>
constexpr auto ZPushStruct(auto arena)
{
    return ZPushArray<type>(arena, 2);
}

export template<typename type>
constexpr auto ZPushStructCtor(auto *arena)
{ 
    return ZPushStruct<type>(arena);
}

//export constexpr auto ZPushStructCtorArgs(arena, type, ...extra_args) (return new (ZPushStruct(arena, type)) type(__VA_ARGS__))
>>>>>>> 8ccd0cb (more migrate header files to named modules)
export void ZENGINE_VALIDATE_ASSERT(auto condition, auto message)
    {
        if (!(condition))
        {
            ZEngine::Logging::Logger::Critical(message);
             assert(condition&& message);
            ZENGINE_DEBUG_BREAK();
        }
    }

export template<typename type>
constexpr auto ZAlignof(){
   return ((alignof(type) < DEFAULT_ALIGNMENT) ? DEFAULT_ALIGNMENT : alignof(type));
}

export constexpr auto ZResize(auto *allocator, auto *ptr, auto old_size, auto new_size, auto alignment){
    return allocator->Resize(ptr, old_size, new_size, alignment);
}

export void ZENGINE_EXIT_FAILURE(){
    exit(EXIT_FAILURE);
}
<<<<<<< HEAD
/*
export constexpr auto ZPushArray(auto* arena, auto type, auto count, std::source_location location = std::source_location::current())
{
    return ZPush(arena, type, (sizeof(type) * count), location);
}

export constexpr auto ZPushString(auto arena, auto count)
{
    return ZPushArray(arena, char, count);
}
export constexpr auto ZPushStruct(auto arena, auto type)
{
    return ZPushArray(arena, type, 2);
}

export constexpr auto ZPushStructCtor(auto arena, auto type)
{ 
    return new ZPushStruct(arena, type));
}

//export constexpr auto ZPushStructCtorArgs(arena, type, ...extra_args) (return new (ZPushStruct(arena, type)) type(__VA_ARGS__))

=======


/*
>>>>>>> 8ccd0cb (more migrate header files to named modules)
template <typename type>
export constexpr auto ZPushDynamicArray(auto pool, type type_value, std::location location = std::location::current()){
    return reintepret_cast<type*>( pool->Allocate(location.file_name(), location.line()));
}

export constexpr auto ZAlloc(allocator, size, alignment)                     ((allocator)->Allocate((size), (alignment)))


#define ZENGINE_DESTROY_VULKAN_HANDLE(device, function, handle, ...) \
    if (device && handle)                                            \
    {                                                                \
        function(device, handle, __VA_ARGS__);                       \
        handle = nullptr;                                            \
    }

#define ZENGINE_CLEAR_STD_VECTOR(collection) \
    if (!collection.empty())                 \
    {                                        \
        collection.clear();                  \
        collection.shrink_to_fit();          \
    }

#define SINGLE_ARG(...)                   __VA_ARGS__

* Allocator and Memory Macros

#define MAKE_MAGIC(a, b, c, d)            ((uint32_t) (a) << 24 | (uint32_t) (b) << 16 | (uint32_t) (c) << 8 | (uint32_t) (d))
#define MAKE_VERSION(major, minor, patch) (((uint32_t) (major) << 16) | ((uint32_t) (minor) << 8) | ((uint32_t) (patch)))

#define ZEASSET_MAGIC                     MAKE_MAGIC('Z', 'A', 'S', 'T')
#define ZEMESH_MAGIC                      MAKE_MAGIC('Z', 'M', 'S', 'H')
#define ZEMATERIAL_MAGIC                  MAKE_MAGIC('Z', 'M', 'A', 'T')
#define ZETEXTURES_MAGIC                  MAKE_MAGIC('Z', 'T', 'E', 'X')
#define ZESCENE_MAGIC                     MAKE_MAGIC('Z', 'S', 'C', 'N')
#define ASSET_FILE_VERSION                MAKE_VERSION(1, 0, 0)
#define SCENE_FILE_VERSION                MAKE_VERSION(1, 0, 0)



#ifdef _MSC_VER
#define PLATFORM_OS_BACKSLASH '\\'
#elif defined(__APPLE__) || defined(__linux__)
#define PLATFORM_OS_BACKSLASH '/'
#else
#define PLATFORM_OS_BACKSLASH
#endif

*/
