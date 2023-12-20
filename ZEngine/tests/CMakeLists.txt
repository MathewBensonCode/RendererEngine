cmake_minimum_required(VERSION 3.17)

project(ZEngineTests)

enable_testing()

find_package(GTest CONFIG REQUIRED)

add_executable(ZEngineTests)

target_sources(ZEngineTests PRIVATE IntrusivePtr_test.cpp
                                    IntrusiveWeakPtr_test.cpp)

target_link_libraries(ZEngineTests GTest::gtest_main zEngineLib)

add_test(NAME ZEngineUnitTests COMMAND ZEngineTests)
