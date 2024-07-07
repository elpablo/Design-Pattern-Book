#include "Model.h"
#include "Observer.h"

void Model::notify()
{
    // broadcasts notifications
    for (int i = 0; i < _observers.size(); ++i)
    {
        _observers[i]->update();
    }
}
