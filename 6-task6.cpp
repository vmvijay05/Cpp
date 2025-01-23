#include <iostream>
#include <string>
using namespace std;

class family
{
public:
    string names[3];
    int count = 0, flag = 0;
    string str = "Vij";
    char *ptr;

    void addName(string name, int count)
    {
        names[count] = name;
    }

    void search()
    {
        for (int i = 0; i < 3; i++)
        {
            if (names[i] == str)
            {
                flag++;
                cout << "The searched string is present" << endl;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "The searched string is not present" << endl;
        }
    }

    void makeupper()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < names[i].length(); j++)
            {
                names[i][j] = toupper(names[i][j]);
            }
        }
    }

    void display(int size)
    {
        cout << "Updates Names lists are: " << endl;
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
        while (k < 3)
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
    details.search();
    details.makeupper();
    details.display(3);
}
