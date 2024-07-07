#include "RunningState.h"
#include "StoppedState.h"
#include "StateMachine.h"


void RunningState::stopped(StateMachine *m)
{
    std::cout << "   transition RunningState -> StoppedState" << std::endl;
    m->setCurrent(new StoppedState());
    delete this;
}
