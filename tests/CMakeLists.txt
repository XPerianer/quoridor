include(FetchContent) FetchContent_Declare(
    googletest URL https
    : // github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
    ) FetchContent_MakeAvailable(googletest)

#We have a custom FAIL macro.Use GTEST_FAIL to refer to the google macro
    add_definitions(-DGTEST_DONT_DEFINE_FAIL)

        add_compile_options(${COMPILER_WARNING_FLAGS})

            file(GLOB_RECURSE ALL_CPP_TEST_FILES *.cpp)

                add_executable(unit_test ${ALL_CPP_TEST_FILES})

                    target_link_libraries(unit_test GTest::gtest_main gmock)

                        include(GoogleTest) gtest_discover_tests(unit_test)
