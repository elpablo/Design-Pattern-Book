#include "Container.h"
#include "ContainerIterator.h"

ContainerIterator *Container::createIterator() const
{
    return new ContainerIterator(this);
}
