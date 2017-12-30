#include <iostream>
#include <vector>

class Order
{
public:
    void buy(int &quantity)
    {
        std::cout << "Buy "
                  << quantity << " Items"
                  << std::endl;
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
    typedef void(Order:: *Action)(int &);
    Order *_receiver;
    Action _action;

public:
    SimpleCommand(Order *rec, Action act)
    {
        _receiver = rec;
        _action = act;
    }

    /*virtual*/ void execute(int &num)
    {
        // Pass the num argument to the called function
        (_receiver->*_action)(num);
    }
};

class MacroCommand: public Command
{
    std::vector<Command *> _list;

public:
    void add(Command *cmd)
    {
        _list.push_back(cmd);
    }

    /*virtual*/ void execute(int &num)
    {
        for (int i = 0; i < _list.size(); i++)
        {
            _list[i]->execute(num);
        }
    }
};

int main()
{
    Order object;
    Command *commands[2];
    SimpleCommand simpleCommand(&object, &Order::buy);
    commands[0] = &simpleCommand;

    MacroCommand buy_twice;
    buy_twice.add(commands[0]);
    buy_twice.add(commands[0]);
    commands[1] = &buy_twice;

    int num, orderer_index;
    while (true)
    {
        std::cout << "Order: ";
        std::cin >> num;
        std::cout << "Times (1 => 1x 2 => 2x): ";
        std::cin >> orderer_index;
        if (orderer_index == 1 || orderer_index == 2) {
            commands[orderer_index-1]->execute(num);
        }
    }

    return 0;
}

//------------------------------------------------------------------------------
/*
Output:

Enter number selection (0=1x 1=2x): 3 0
   3
Enter number selection (0=1x 1=2x): 3 1
   12
Enter number selection (0=1x 1=2x): 4 0
   8
Enter number selection (0=1x 1=2x): 4 1
   16
*/
