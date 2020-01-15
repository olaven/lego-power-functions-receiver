#define CATCH_CONFIG_MAIN
#include "./catch.hpp"

TEST_CASE("Getting to know catch2") {
  REQUIRE(1 == 1);
  REQUIRE(1 != 1);
}
