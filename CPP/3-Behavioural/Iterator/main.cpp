#include "ContainerIterator.h"
#include "Container.h"

#include <iostream>

int main()
{
    Container stack;
    for (int i = 1; i < 5; i++)
    {
        stack.push(i);
    }

    ContainerIterator *iter = stack.createIterator();

    while (!iter->isDone())
    {
        std::cout << "Item: " << iter->currentItem() << std::endl;
        iter->next();
    }

    delete iter;

    return 0;
}


/*
 Output:

 Item: 1
 Item: 2
 Item: 3
 Item: 4

*/
