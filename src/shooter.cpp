#include "shooter.h"
#include <iostream>

Shooter::Shooter(Die& d1, Die& d2) : die1(d1), die2(d2) {}

Roll* Shooter::throw_dice() {
    Roll* newRoll = new Roll(die1, die2);
    newRoll->roll_dice();
    rolls.push_back(newRoll);
    return newRoll;
}

void Shooter::display_rolled_values() const {
    for (const auto& roll : rolls) {
        std::cout << roll->roll_value() << std::endl;
    }
}

Shooter::~Shooter() {
    for (auto& roll : rolls) {
        delete roll;
    }
    rolls.clear();
}