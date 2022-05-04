#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "header.hpp"

TEST_CASE("add", "[header.hpp]") { REQUIRE(add(3, 5) ==  8); }
TEST_CASE("sub", "[header.hpp]") { REQUIRE(sub(3, 5) == -2); }