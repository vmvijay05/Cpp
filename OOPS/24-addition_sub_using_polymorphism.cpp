#include <iostream>
#include <string>
using namespace std;

class Calculator
{
public:
    int calculate(int a, int b)
    {
        return a + b;
    }

    double calculate(double a, double b)
    {
        return a + b;
    }

    string calculate(string a, string b)
    {
        return a + b;
    }

    double calculate(int a, double b)
    {
        return a + b;
    }

    double calculate(double a, int b)
    {
        return a + b;
    }
};

int main()
{
    Calculator calc;

    cout << "Integer addition (5 + 3): " << calc.calculate(5, 3) << endl;

    cout << "Double addition (5.5 + 3.2): " << calc.calculate(5.5, 3.2) << endl;

    cout << "String concatenation (\"Hello\" + \" World\"): " << calc.calculate(string("Hello"), string(" World")) << endl;

}

