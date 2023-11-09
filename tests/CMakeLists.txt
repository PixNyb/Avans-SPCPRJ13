cmake_minimum_required(VERSION 3.27)

project(DeFunBobEngine-Test)

# Test the demo_test.cpp file
add_executable(DemoTest demo_test.cpp)

add_test(NAME DemoTest COMMAND DemoTest)

set(DemoPassRegex "Passed" "PASSED" "passed")

set_property(TEST DemoTest PROPERTY PASS_REGULAR_EXPRESSION ${DemoPassRegex})