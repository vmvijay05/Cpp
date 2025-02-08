#include <iostream>
using namespace std;

class Example
{
public:
    static int count; // Static variable declaration

    void increment()
    {
        count++; // Increment static variable
    }

    void displayCount()
    {
        cout << "Count: " << count << endl;
    }
};

// Define and initialize the static variable outside the class
int Example::count = 0; //(If the static variable initialize the value inside the function the keyword "inline" should be used. eg: static inline count=0;)

int main()
{
    Example obj1, obj2;

    obj1.increment();
    obj1.displayCount();

    obj2.increment();    // Increment using obj2
    obj2.displayCount(); // Count: 2
obj1.increment();
    obj1.displayCount();

}
