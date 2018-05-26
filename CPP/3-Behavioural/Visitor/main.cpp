#include "PageModel.h"
#include "Visitor.h"

#include <iostream>
#include <string>

int main()
{
    Page page;

    UppercaseVisitor up;
    LowercaseVisitor low;

    page.accept(up);
    std::cout << "Visited Uppercase text: " << up.text() << std::endl;

    page.accept(low);
    std::cout << "Visited Lowercase text: " << low.text() << std::endl;

    return 0;
}

/*
 Output:

 Visited Uppercase text: PAGE TEXT
 Visited Lowercase text: page text

 */
