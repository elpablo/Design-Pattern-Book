#ifndef __StateMachine_h
#define __StateMachine_h

#include <iostream>

class State;


class StateMachine
{
    State *_currentState;

public:
    StateMachine();

    void setCurrent(State *s)
    {
        _currentState = s;
    }

    void run();

    void stop();
};

#endif
