#include "StackIter.h"
#include "Stack.h"

#include <iostream>

int main()
{
    Stack s1;
    for (int i = 1; i < 5; i++)
    {
        s1.push(i);
    }

    Stack s2(s1), s3(s1), s4(s1), s5(s1);

    s3.pop();
    s5.pop();
    s4.push(2);
    s5.push(9);

    std::cout << "s1 == s2 is " << (s1 == s2) << std::endl;
    std::cout << "s1 == s3 is " << (s1 == s3) << std::endl;
    std::cout << "s1 == s4 is " << (s1 == s4) << std::endl;
    std::cout << "s1 == s5 is " << (s1 == s5) << std::endl;

    return 0;
}


/*
 Output:

 s1 == s2 is 1
 s1 == s3 is 0
 s1 == s4 is 0
 s1 == s5 is 0

*/
