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

    ContainerIterator *iter = stack.create_iterator();
    
    while (!iter->is_done())
    {
        std::cout << "Item: " << iter->current_item() << std::endl;
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
