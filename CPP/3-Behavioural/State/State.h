#ifndef __State_h
#define __State_h

#include <iostream>

class StateMachine;

class State
{
public:
    virtual void running(StateMachine *m)
    {
        std::cout << "   already Running\n";
    }

    virtual void stopped(StateMachine *m)
    {
        std::cout << "   already Stopped\n";
    }
};

#endif
