#include "math_utils.hpp"
#include <gtest/gtest.h>
#include <vector>

// Test de la función add()
TEST(MathUtilsTest, AddBasic) {
    EXPECT_EQ(math_utils::add(2, 3), 5);
    EXPECT_EQ(math_utils::add(-1, 1), 0);
    EXPECT_EQ(math_utils::add(0, 0), 0);
}

// Test de la función average()
TEST(MathUtilsTest, AverageBasic) {
    std::vector<int> nums = {2, 4, 6, 8};
    EXPECT_DOUBLE_EQ(math_utils::average(nums), 5.0);
}

TEST(MathUtilsTest, AverageEmptyVector) {
    std::vector<int> empty;
    EXPECT_DOUBLE_EQ(math_utils::average(empty), 0.0);
}