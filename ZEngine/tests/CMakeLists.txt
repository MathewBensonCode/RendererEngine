cmake_minimum_required(VERSION 3.17)

project(ZEngineTests)

enable_testing()

add_executable(ZEngineTests)

target_sources(ZEngineTests PRIVATE 
shaderCompiler_test.cpp
ThreadPool_test.cpp
IntrusiveWeakPtr_test.cpp
IntrusivePtr_test.cpp
bitmap_test.cpp
MemoryOperation_test.cpp
)

target_link_libraries(ZEngineTests PRIVATE
    zEngineLib
    GTest::gtest_main)

add_test(NAME ZEngineUnitTests COMMAND ZEngineTests)
