#include <iostream>

class Wallet;

class Memento
{
public:
    Memento(int val)
    {
        _state = val;
    }

private:
    friend class Wallet; // not essential
    int _state;
};

class Wallet
{
public:
    Wallet(int value)
    {
        _value = value;
    }

    void deposit()
    {
        _value = 2 * _value;
    }

    void withdraw()
    {
        _value = _value / 2;
    }

    int getValue()
    {
        return _value;
    }

    Memento *createMemento()
    {
        return new Memento(_value);
    }

    void assignMemento(Memento *mem)
    {
        _value = mem->_state;
    }

private:
    int _value;
};

class Command
{
public:
    typedef void(Wallet:: *Action)();

    Command(Wallet *receiver, Action action)
    {
        _receiver = receiver;
        _action = action;
    }

    virtual void execute()
    {
        _mementoList[_numCommands] = _receiver->createMemento();
        _commandList[_numCommands] = this;
        if (_numCommands > _highWater)
        {
            _highWater = _numCommands;
        }
        _numCommands++;
        (_receiver->*_action)();
    }

    static void undo()
    {
        if (_numCommands == 0)
        {
            std::cout << "*** Attempt to run off the end!! ***" << std::endl;
            return ;
        }
        _commandList[_numCommands - 1]->_receiver->assignMemento(_mementoList[_numCommands - 1]);
        _numCommands--;
    }

    void static redo()
    {
        if (_numCommands > _highWater)
        {
            std::cout << "*** Attempt to run off the end!! ***" << std::endl;
            return ;
        }
        (_commandList[_numCommands]->_receiver->*(_commandList[_numCommands]->_action))();
        _numCommands++;
    }

protected:
    Wallet *_receiver;
    Action _action;
    static Command *_commandList[20];
    static Memento *_mementoList[20];
    static int _numCommands;
    static int _highWater;
};

Command *Command::_commandList[];
Memento *Command::_mementoList[];
int Command::_numCommands = 0;
int Command::_highWater = 0;

int main()
{
    int i;
    std::cout << "Amount: ";
    std::cin >> i;
    Wallet *wallet = new Wallet(i);

    Command *commands[3];
    commands[1] = new Command(wallet, &Wallet::deposit);
    commands[2] = new Command(wallet, &Wallet::withdraw);

    std::cout << "Exit[0], Deposit[1], Withdraw[2], Undo[3], Redo[4]: ";
    std::cin >> i;

    while (i)
    {
        if (i == 3)
        {
            Command::undo();
        }
        else if (i == 4)
        {
            Command::redo();
        }
        else
        {
            commands[i]->execute();
        }

        std::cout << "   " << wallet->getValue() << std::endl;
        std::cout << "Exit[0], Deposit[1], Withdraw[2], Undo[3], Redo[4]: ";
        std::cin >> i;
    }

    delete commands[1];
    delete commands[2];
    delete wallet;

    return 0;
}

//------------------------------------------------------------------------------
/*
Output:

Amount: 11
Exit[0], Deposit[1], Withdraw[2], Undo[3], Redo[4]: 2
   5
Exit[0], Deposit[1], Withdraw[2], Undo[3], Redo[4]: 1
   10
Exit[0], Deposit[1], Withdraw[2], Undo[3], Redo[4]: 2
   5
Exit[0], Deposit[1], Withdraw[2], Undo[3], Redo[4]: 3
   10
Exit[0], Deposit[1], Withdraw[2], Undo[3], Redo[4]: 3
   5
Exit[0], Deposit[1], Withdraw[2], Undo[3], Redo[4]: 3
   11
Exit[0], Deposit[1], Withdraw[2], Undo[3], Redo[4]: 3
*** Attempt to run off the end!! ***
   11
Exit[0], Deposit[1], Withdraw[2], Undo[3], Redo[4]: 4
   5
Exit[0], Deposit[1], Withdraw[2], Undo[3], Redo[4]: 4
   10
Exit[0], Deposit[1], Withdraw[2], Undo[3], Redo[4]: 4
   5
Exit[0], Deposit[1], Withdraw[2], Undo[3], Redo[4]: 4
*** Attempt to run off the end!! ***
   5
*/
