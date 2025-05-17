#pragma once
#include "roll.h"
#include <vector>

class Shooter {
public:
    Shooter(Die& d1, Die& d2);
    Roll* throw_dice();
    void display_rolled_values() const;
    ~Shooter();

private:
    std::vector<Roll*> rolls;
    Die& die1;
    Die& die2;
};