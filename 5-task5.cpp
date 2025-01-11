//Input string name getting from user and store one array using class and object.

#include <iostream>
#include <string>
using namespace std;

class family
{
public:
    string names[5];
    int count=0;
    void addName(string name, int count)
    {
        names[count] = name;
        //count++;
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
        int k = 0;
        while (k < 5)
        {
            cout << "Enter name: ";
            getline(cin, name);
            k++;
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
    details.display(5);
}
