add_test( [==[Empty arrays have certain properties]==] /home/cameron/home/source/repos/CMakeProject1/test/test/test_array2d [==[Empty arrays have certain properties]==])
set_tests_properties( [==[Empty arrays have certain properties]==] PROPERTIES WORKING_DIRECTORY /home/cameron/home/source/repos/CMakeProject1/test/test)
add_test( [==[Non-empty arrays have certain properties]==] /home/cameron/home/source/repos/CMakeProject1/test/test/test_array2d [==[Non-empty arrays have certain properties]==])
set_tests_properties( [==[Non-empty arrays have certain properties]==] PROPERTIES WORKING_DIRECTORY /home/cameron/home/source/repos/CMakeProject1/test/test)
set( test_array2d_TESTS [==[Empty arrays have certain properties]==] [==[Non-empty arrays have certain properties]==])
