#include "Stack.h"
#include "StackIter.h"

StackIter *Stack::create_iterator() const
{
    return new StackIter(this);
}
