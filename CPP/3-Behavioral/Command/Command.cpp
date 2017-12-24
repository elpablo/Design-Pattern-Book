#include <iostream>
#include <vector>

class Number
{
public:
    void dubble(int &value)
    {
        value *= 2;
    }
};

class Command
{
public:
    virtual ~Command() {}
    virtual void execute(int &) = 0;
};

class SimpleCommand: public Command
{
    // Define a type to match the function to call
    typedef void(Number:: *Action)(int &);
    Number *receiver;
    Action action;

public:
    SimpleCommand(Number *rec, Action act)
    {
        receiver = rec;
        action = act;
    }

    /*virtual*/ void execute(int &num)
    {
        // Pass the num argument to the called function
        (receiver->*action)(num);
    }
};

class MacroCommand: public Command
{
    std::vector<Command *> list;

public:
    void add(Command *cmd)
    {
        list.push_back(cmd);
    }

    /*virtual*/ void execute(int &num)
    {
        for (int i = 0; i < list.size(); i++)
        {
            list[i]->execute(num);
        }
    }
};

int main()
{
    Number object;
    Command *commands[3];
    SimpleCommand simpleCommand(&object, &Number::dubble);
    commands[0] = &simpleCommand;

    MacroCommand two;
    two.add(commands[0]);
    two.add(commands[0]);
    commands[1] = &two;

    MacroCommand four;
    four.add(&two);
    four.add(&two);
    commands[2] = &four;

    int num, multiplier_index;
    while (true)
    {
        std::cout << "Number: ";
        std::cin >> num;
        std::cout << "Multiplier (0 => 2x 1 => 4x 2 => 16x):";
        std::cin >> multiplier_index;
        commands[multiplier_index]->execute(num);
        std::cout << "   " << num << std::endl;
    }

    return 0;
}

//------------------------------------------------------------------------------
/*
Output:

Enter number selection (0=2x 1=4x 2=16x): 3 0
   6
Enter number selection (0=2x 1=4x 2=16x): 3 1
   12
Enter number selection (0=2x 1=4x 2=16x): 3 2
   48
Enter number selection (0=2x 1=4x 2=16x): 4 0
   8
Enter number selection (0=2x 1=4x 2=16x): 4 1
   16
Enter number selection (0=2x 1=4x 2=16x): 4 2
   64
*/
