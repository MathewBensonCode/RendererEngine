file ( GLOB TEST_SOURCES 
            Memory/*.cpp
            Containers/*.cpp
            Maths/*.cpp
            Misc/*.cpp)

add_executable(ZEngineTests)

target_sources(ZEngineTests PRIVATE ${TEST_SOURCES})

target_link_libraries(ZEngineTests PRIVATE
    zEngineLib
    GTest::gtest_main
)

install(TARGETS ZEngineTests 
    RUNTIME DESTINATION tests)

if(BUILD_TESTING)
    include(GoogleTest)
    gtest_discover_tests(ZEngineTests)
endif()
