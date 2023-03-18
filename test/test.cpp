#include <catch2/catch_test_macros.hpp> 

// NB: Catch2 takes care of providing main for the tests through the Cmake target Catch2WithMain
// See: https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#cmake-targets


TEST_CASE("Dummy Test") {
constexpr int pi_approx{3};
  REQUIRE(pi_approx == 0b011);
};
