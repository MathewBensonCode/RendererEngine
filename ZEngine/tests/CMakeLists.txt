add_executable(ZEngineTests)

target_sources(ZEngineTests
    PRIVATE
    Misc/shaderCompiler_test.cpp
    Misc/ThreadPool_test.cpp
    Memory/IntrusiveWeakPtr_test.cpp
    Memory/IntrusivePtr_test.cpp
    Memory/handleManager_test.cpp
    Memory/bitmap_test.cpp
    Memory/allocator_test.cpp
    Memory/MemoryOperation_test.cpp
    Containers/string_test.cpp
    Containers/array_test.cpp
    Containers/initializerlist_test.cpp
    Containers/hashmap_test.cpp
    Maths/Matrix_test.cpp
    Maths/Vector_test.cpp
)

target_link_libraries(ZEngineTests PRIVATE
    zEngineLib
    GTest::gtest_main
)
