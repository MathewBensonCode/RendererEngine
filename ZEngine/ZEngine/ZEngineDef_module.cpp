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
import ZEngine.Logging;

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

export template<typename type>
constexpr type* ZPushArray(auto* arena, auto count, std::source_location location = std::source_location::current())
{
    return reinterpret_cast<type*>(ZPush(arena, (sizeof(type) * count), location));
}

export constexpr char* ZPushString(auto *arena, auto count)
{
    return ZPushArray<char>(arena, count);
}

export template<typename type>
constexpr type* ZPushStruct(auto* arena)
{
    return ZPushArray<type>(arena, 2);
}

export template<typename type>
constexpr type* ZPushStructCtor(auto *arena)
{ 
    return new (ZPushStruct<type>(arena)) type();
}

export template<typename type, typename ...args>
constexpr type* ZPushStructCtorArgs(auto *arena, args... extra_args){
    return new (ZPushStruct<type>(arena)) type(extra_args...);
}

export void ZENGINE_VALIDATE_ASSERT(bool condition, auto message)
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


export template <typename type>
constexpr type* ZPushDynamicArray(auto pool, std::source_location location = std::source_location::current()){
    return reintepret_cast<type*>( pool->Allocate(location.file_name(), location.line()));
}

export constexpr auto* ZAlloc(auto *allocator, auto size, auto alignment)
{
    return ((allocator)->Allocate((size), (alignment)));
}

export template<typename ...args>
void ZENGINE_DESTROY_VULKAN_HANDLE(auto *device, auto function, auto *handle, args... extra_args)
{
    if (device && handle)                                            
    {                                                                
        function(device, handle, extra_args...);                       
        handle = nullptr;                                            
    }
}

export auto ZENGINE_CLEAR_STD_VECTOR(auto &collection){
    if (!collection.empty())                 
    {                                        
        collection.clear();                  
        collection.shrink_to_fit();          
    }
}

/*
#define SINGLE_ARG(...)                   __VA_ARGS__


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
