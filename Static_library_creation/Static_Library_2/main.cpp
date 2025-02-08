#include <iostream>
#include "StringLength.h"
using namespace std;

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    int length = getStringLength(input);
    cout << "The length of the string is: " << length << endl;

    return 0;
}

