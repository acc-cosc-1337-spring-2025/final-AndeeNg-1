#include "roll.h"

Roll::Roll(Die& d1, Die& d2) : die1(d1), die2(d2) {}

void Roll::roll_dice() {
    int val1 = die1.roll();
    int val2 = die2.roll();
    rolled_value = val1 + val2;
}

int Roll::roll_value() const {
    return rolled_value;
}