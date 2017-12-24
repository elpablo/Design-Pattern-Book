#include <iostream>

class Chart
{
    void vettingData()
    {
        std::cout << "remove non valid values -> ";
    }

    void featuresExtraction()
    {
        std::cout << "extract chart data -> ";
    }

protected:
    // Steps requiring peculiar implementations
    // are "placeholders" in base class
    virtual void readData() = 0;
    virtual void drawData() = 0;

public:
    virtual ~Chart() {}

    // Standardize the skeleton of an algorithm
    // in a base class "template method"
    void execute()
    {
        readData();
        vettingData();
        featuresExtraction();
        drawData();
    }
};

class LineChart: public Chart
{
    // Derived classes implement placeholder methods
    /*virtual*/ void readData()
    {
        std::cout << "read LineChart data -> ";
    }

    /*virtual*/ void drawData()
    {
        std::cout << "Draw data as line chart";
    }
};

class PieChart: public Chart
{
    // Derived classes implement placeholder methods
    /*virtual*/ void readData()
    {
        std::cout << "read PieChart data -> ";
    }

    /*virtual*/ void drawData()
    {
        std::cout << "Draw data as pie chart";
    }
};

int main()
{
    Chart *array[] =
    {
        new LineChart(), new PieChart()
    };

    for (int i = 0; i < 2; i++)
    {
        array[i]->execute();
        std::cout << '\n';
    }

    delete array[0];
    delete array[1];
    return 0;
}

/*
 Output:

 "read LineChart data"  ->  "remove non valid values"  ->  "extract chart data"  ->  "Draw data as line chart"
 "read PieChart data"  ->  "remove non valid values"  ->  "extract chart data"  ->  "Draw data as pie chart"

 */
