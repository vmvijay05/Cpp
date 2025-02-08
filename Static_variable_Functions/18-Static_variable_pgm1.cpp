/*  Explanation:
Static Variable:
* Declared inside the increment() method using the static keyword.
* A static variable retains its value across multiple calls to the function.
* It is initialized only once, and its value persists for the lifetime of the program.
* Output: Each time increment() is called, the value of count increases by 1 because it retains its value between function calls.  */

#include <iostream>
using namespace std;

class Counter
{
public:
    void increment()
    {
        static int count = 0; // Static variable declaration
        count++;
        cout << "Count: " << count << endl;
    }
};

int main()
{
    Counter c1, c2;

    // Calling increment() multiple times
    c1.increment(); // Count: 1
    c2.increment(); // Count: 2
    c1.increment(); // Count: 3
    c2.increment(); // Count: 4
}
