/**
 * This file contains unit tests for the Add function.
 *
 * We use Google Test as our testing framework. Here's a basic guide on how to write tests:
 *
 * 1. Include the gtest header: `#include "gtest/gtest.h"`
 *
 * 2. Write a test using the TEST macro. The first argument is the test suite name, and the second
 *    argument is the test name. For example: `TEST(AddTest, PositiveNumbers)`
 *
 * 3. Inside the test, use the various Google Test assertions to check your function's behavior.
 *    For example: `EXPECT_EQ(Add(1, 2), 3);`
 *
 * 4. At the end of your file, you should have a main function that runs all the tests:
 *    ```
 *    int main(int argc, char **argv)
 *    {
 *        testing::InitGoogleTest(&argc, argv);
 *        return RUN_ALL_TESTS();
 *    }
 *    ```
 *
 * You can add more tests for the Add function by adding more TEST blocks.
 */

#include "gtest/gtest.h"

int Add(int a, int b) { return a + b; }

TEST(AddTest, PositiveNumbers) { EXPECT_EQ(Add(1, 2), 3); }

TEST(AddTest, NegativeNumbers) { EXPECT_EQ(Add(-1, -2), -3); }

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}