#include "StateMachine.h"

#include <iostream>

int main()
{
    StateMachine fullStateStateMachine;
    int num(0);
    while (num != 2)
    {
        std::cout << "0 to Stop, 1 to Run, 2 to Exit: ";
        std::cin >> num;

        if (num == 0) {
            fullStateStateMachine.stop();
        } else if (num == 1) {
            fullStateStateMachine.run();
        }
    }

    return 0;
}

//------------------------------------------------------------------------------
/*
Output:

Enter 0/1: 0
  already Stopped
Enter 0/1: 1
  going transition StoppedState -> RunningState
Enter 0/1: 1
  already Running
Enter 0/1: 0
  going transition RunningState -> StoppedState
Enter 0/1: 1
  going transition StoppedState -> RunningState
Enter 0/1: 0
  going transition RunningState -> StoppedState
Enter 0/1: 0
  already Stopped
Enter 0/1:
*/
