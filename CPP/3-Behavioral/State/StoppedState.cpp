#include "StoppedState.h"
#include "RunningState.h"
#include "StateMachine.h"


void StoppedState::running(StateMachine *m)
{
    std::cout << "   transition StoppedState -> RunningState" << std::endl;
    m->setCurrent(new RunningState());
    delete this;
}
