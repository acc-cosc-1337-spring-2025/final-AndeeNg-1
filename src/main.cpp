#include <iostream>
#include <ctime>
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

int main() 
{
	std::srand(std::time(0));

    Die die1, die2;
    Shooter shooter(die1, die2);

    Roll* roll = shooter.throw_dice();

    ComeOutPhase come_out_phase;

    while (true) {
        RollOutcome outcome = come_out_phase.get_outcome(roll);
        int rolled_value = roll->roll_value();

        if (outcome == RollOutcome::natural || outcome == RollOutcome::craps) {
            std::cout << "Rolled " << rolled_value << " roll again\n";
            roll = shooter.throw_dice();
        } else {
            std::cout << "Rolled " << rolled_value << " start of point phase\n";
            break;
        }
    }

    int point = roll->roll_value();

    std::cout << "Roll until " << point << " or a 7 is rolled\n";

    PointPhase point_phase(point);

    while (true) {
        roll = shooter.throw_dice();
        int rolled_value = roll->roll_value();

        RollOutcome outcome = point_phase.get_outcome(roll);

        if (outcome == RollOutcome::seven_out) {
            std::cout << "Rolled " << rolled_value << " end of point phase\n";
            break;
        } else if (outcome == RollOutcome::point) {
            std::cout << "Rolled " << rolled_value << " end of point phase\n";
            break;
        } else {
            std::cout << "Rolled " << rolled_value << " roll again\n";
        }
    }

    shooter.display_rolled_values();

	return 0;
}