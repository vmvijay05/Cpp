// Input string name getting from user and store one array using class and object.

#include <iostream>
#include <string>
using namespace std;

class family
{
public:
    string names[3];
    int count = 0;
    void addName(string name, int count)
    {
        names[count] = name;
        // count++;
    }

    void display(int size)
    {
        cout << "Names in the list:" << endl;
        for (int j = 0; j < size; j++)
        {
            cout << names[j] << endl;
        }
    }

    void collectNames()
    {
        string name;
        int i = 0;
        while (i < 3)
        {
            cout << "Enter name: ";
            getline(cin, name);
            i++;
            if (name == "done")
            {
                break;
            }
            addName(name, count);
            count++;
        }
    }
};

int main()
{
    family details;
    details.collectNames();
    details.display(3);
}
