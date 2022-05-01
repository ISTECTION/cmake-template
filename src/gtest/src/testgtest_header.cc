#include <gtest/gtest.h>

#include "../../../include/header.hpp"

TEST(SquareRootTest, PositiveNos2) {
    ASSERT_EQ(6,    squareRoot(36.0));
    ASSERT_EQ(18.0, squareRoot(324.0));
}