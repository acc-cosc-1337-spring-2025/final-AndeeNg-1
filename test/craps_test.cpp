#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../src/shooter.h"

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

TEST_CASE("Verify Roll returns values between 2 and 12", "[roll]") {
    Die die1;
    Die die2;
    Roll roll(die1, die2);

    for (int i = 0; i < 10; ++i) {
        roll.roll_dice();
        int value = roll.roll_value();
        REQUIRE(value >= 2);
        REQUIRE(value <= 12);
    }
}

TEST_CASE("Shooter returns Roll with value between 2 and 12", "[shooter]") {
    Die die1;
    Die die2;
    Shooter shooter;

    for (int i = 0; i < 10; ++i) {
        Roll* roll = shooter.throw_dice(die1, die2);
        int result = roll->roll_value();
        REQUIRE(result >= 2);
        REQUIRE(result <= 12);
    }

    shooter.display_rolled_values();
}