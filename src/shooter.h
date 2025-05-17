#include "roll.h"
#include <vector>

class Shooter {
public:
    Roll* throw_dice(Die& die1, Die& die2); 
    void display_rolled_values() const; 
    ~Shooter();

private:
    std::vector<Roll*> rolls;
};