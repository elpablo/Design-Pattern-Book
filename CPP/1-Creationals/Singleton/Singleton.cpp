#include <iostream>

class MySingleton
{
private:
    MySingleton() {}

public:
    static MySingleton& getInstance()
    {
        static MySingleton instance; // Guaranteed to be destroyed.
                                     // Instantiated on first use.
        return instance;
    }

    void do_something(int param)
    {
        std::cout << "Do something... " << param << std::endl;
    }
};

// Example usage of Singleton object
int main()
{
    MySingleton s = MySingleton::getInstance();
    s.do_something(42);

    return 0;
}

//-----------------------------------------------------------
/*
Output:

Do something... 42

*/
