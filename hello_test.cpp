#include <gtest/gtest.h>

int multiply(int a, int b) { return a * b; }

TEST(LLCycleTest, HashMap) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(multiply(4, 8), 4 * 8);
}
