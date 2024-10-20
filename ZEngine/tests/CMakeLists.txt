cmake_minimum_required(VERSION 3.17)

project(ZEngineTests)

Find_Package(GTest REQUIRED)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(ZEngineTests ${TEST_SOURCES})

target_link_libraries(ZEngineTests GTest::gtest_main)

target_link_libraries(ZEngineTests zEngineLib)

add_test(NAME ZEngineUnitTests COMMAND ZEngineTests)
