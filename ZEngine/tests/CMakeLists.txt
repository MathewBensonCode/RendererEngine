cmake_minimum_required(VERSION 3.17)

project(ZEngineTests)

find_package(GTest REQUIRED)

enable_testing()

file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(ZEngineTests ${TEST_SOURCES})

target_link_libraries(ZEngineTests PUBLIC zEngineLib GTest::gtest_main )

add_test(NAME ZEngineUnitTests COMMAND ZEngineTests)
