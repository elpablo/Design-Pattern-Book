#include "Subject.h"
#include "Observer.h"

void Subject::notify()
{
    // Publisher broadcasts
    for (int i = 0; i < _views.size(); ++i)
    {
        _views[i]->update();
    }
}
