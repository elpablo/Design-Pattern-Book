#ifndef __RunningState_h
#define __RunningState_h

#include "State.h"

class RunningState: public State
{
public:
    /*virtual*/ void stopped(StateMachine *m);
};

#endif
