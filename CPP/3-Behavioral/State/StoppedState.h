#ifndef __StoppedState_h
#define __StoppedState_h

#include "State.h"

class StoppedState: public State
{
public:
    /*virtual*/ void running(StateMachine *m);
};

#endif
