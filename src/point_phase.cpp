#include "point_phase.h"

PointPhase::PointPhase(int p) : point(p) {}

RollOutcome PointPhase::get_outcome(Roll* roll) {
    int val = roll->roll_value();
    if (val == point) return RollOutcome::point;
    if (val == 7) return RollOutcome::seven_out;
    return RollOutcome::nopoint;
}