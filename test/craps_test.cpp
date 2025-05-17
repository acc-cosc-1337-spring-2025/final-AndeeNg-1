#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../src/die.h"
#include "../src/roll.h"
#include "../src/shooter.h"
#include "../src/come_out_phase.h"
#include "../src/point_phase.h"

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

TEST_CASE("Roll returns values between 2 and 12", "[roll]") {
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
    Shooter shooter(die1, die2);

    for (int i = 0; i < 10; ++i) {
        Roll* roll = shooter.throw_dice();
        REQUIRE(roll->roll_value() >= 2);
        REQUIRE(roll->roll_value() <= 12);
    }
}

class TestRoll : public Roll {
public:
    TestRoll() : Roll(dummy_die1, dummy_die2) {}
    void set_rolled_value(int val) { rolled_value = val; }
    static Die dummy_die1;
    static Die dummy_die2;
};

Die TestRoll::dummy_die1;
Die TestRoll::dummy_die2;

TEST_CASE("ComeOutPhase returns correct RollOutcome", "[come_out_phase]") {
    ComeOutPhase phase;

    auto testOutcome = [&](int val, RollOutcome expected) {
        TestRoll roll;
        roll.set_rolled_value(val);
        REQUIRE(phase.get_outcome(&roll) == expected);
    };

    testOutcome(7, RollOutcome::natural);
    testOutcome(11, RollOutcome::natural);
    testOutcome(2, RollOutcome::craps);
    testOutcome(3, RollOutcome::craps);
    testOutcome(12, RollOutcome::craps);
    testOutcome(5, RollOutcome::point);
}

TEST_CASE("PointPhase returns correct RollOutcome", "[point_phase]") {
    int point = 6;
    PointPhase phase(point);

    auto testOutcome = [&](int val, RollOutcome expected) {
        TestRoll roll;
        roll.set_rolled_value(val);
        REQUIRE(phase.get_outcome(&roll) == expected);
    };

    testOutcome(6, RollOutcome::point);
    testOutcome(7, RollOutcome::seven_out);
    testOutcome(5, RollOutcome::nopoint);
}