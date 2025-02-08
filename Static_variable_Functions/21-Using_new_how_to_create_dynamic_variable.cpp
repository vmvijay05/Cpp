#include <iostream>
// #include <memory>
using namespace std;

int main()
{
    int *ptr;      // pointer to store the address returned by the new
    ptr = new int; // allocating memory for integer

    *ptr = 10;

    cout << "the Address: " << ptr << endl;
    cout << "the Value: " << *ptr;
}
