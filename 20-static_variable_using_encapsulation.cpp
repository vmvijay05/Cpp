// Static variable program by using public and private.

#include <iostream>
using namespace std;

class Counter
{
private:
    static int count; // Static variable

public:
    static void increment()
    {
        count++;
    }
    static int getCount()
    {
        return count;
    }
};

int Counter::count = 0;

int main()
{
    Counter::increment();
    Counter::increment();
    cout << "Count: " << Counter::getCount() << endl;
}
