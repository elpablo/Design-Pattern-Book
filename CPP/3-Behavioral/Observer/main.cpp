#include "Subject.h"
#include "Observer.h"


int main()
{
    Subject subj;
    // Client configures the number and...
    DivObserver divObs1(&subj, 4);
    DivObserver divObs2(&subj, 3);
    // ...type of Observers
    ModObserver modObs3(&subj, 3);

    // Change the subject’s value to trigger
    // the notification for the observers
    subj.setVal(14);

    return 0;
}

//------------------------------------------------------------------------------
/*
Output:

14 div 4 is 3
14 div 3 is 4
14 mod 3 is 2
*/
