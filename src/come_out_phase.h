#include "phase.h"

class ComeOutPhase : public Phase {
public:
    ComeOutPhase() = default;
    RollOutcome get_outcome(Roll* roll) override;
};
