#include "die.h"
#include <random>

int Die::roll() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, sides);
    return distr(gen);
}