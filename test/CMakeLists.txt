# This has the `catch_discover_tests` definition
include(catch/Catch.cmake)

# This library will help reduce compilation times
add_library(catch OBJECT main.cc)
target_compile_features(catch PUBLIC cxx_std_14)

# Creates a test executable
add_executable(test_array2d array2d.cc $<TARGET_OBJECTS:catch>)
target_link_libraries(test_array2d PRIVATE array2d)

# This integrates each TEST_CASE with CTest
catch_discover_tests(test_array2d)

# This isn't needed because of catch_discover_tests
# add_test(test_array2d test_array2d)
