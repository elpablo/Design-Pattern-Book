#include "Container.h"
#include "ContainerIterator.h"

ContainerIterator *Container::create_iterator() const
{
    return new ContainerIterator(this);
}
