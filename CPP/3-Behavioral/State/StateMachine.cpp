#include "StateMachine.h"
#include "StoppedState.h"

StateMachine::StateMachine()
{
    _currentState = new StoppedState();
}

void StateMachine::run()
{
    _currentState->running(this);
}

void StateMachine::stop()
{
    _currentState->stopped(this);
}
