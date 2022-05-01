#include <gtest/gtest.h>

#include "../../../include/header.hpp"

TEST(SquareRootTest, PositiveNos1) {
    ASSERT_EQ(25.4, squareRoot(645.16));
    ASSERT_EQ(0,    squareRoot(0.0));
}