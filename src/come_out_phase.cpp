#include "come_out_phase.h"

RollOutcome ComeOutPhase::get_outcome(Roll* roll) {
    int val = roll->roll_value();
    if (val == 7 || val == 11) return RollOutcome::natural;
    if (val == 2 || val == 3 || val == 12) return RollOutcome::craps;
    return RollOutcome::point;
}