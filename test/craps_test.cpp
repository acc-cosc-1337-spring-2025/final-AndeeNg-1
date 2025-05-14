#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../src/die.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Die roll returns a number between 1 and 6", "[die]") {
    Die die;

    for (int i = 0; i < 10; ++i) {
        int roll_result = die.roll();
        REQUIRE(roll_result >= 1);
        REQUIRE(roll_result <= 6);
    }
}