#pragma once
#include "die.h"

class TestRoll;

class Roll {
public:
    Roll(Die& d1, Die& d2);
    void roll_dice();
    int roll_value() const;

private:
    Die& die1;
    Die& die2;
    int rolled_value {0};

    friend class TestRoll;
};