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
        this->names[count] = name;
    }

    bool search(string temp)
    {
        cout << "The search string is: " << temp << endl;
        for (int i = 0; i < count; i++)
        {
            cout << "Comparing with: " << names[i] << endl;
            if (names[i] == temp)
            {
                cout << "Found the string: " << temp << endl;
                return true;
            }
        }
        return false;
    }

    void makeupper()
    {
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < names[i].length(); j++)
            {
                names[i][j] = toupper(names[i][j]);
            }
        }
    }

    void display()
    {
        cout << "Updated Names list:" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << names[i] << endl;
        }
    }

    void collectNames()
    {
        string name;
        while (count < 3)
        {
            cout << "Enter name (type 'done' to finish): ";
            getline(cin, name);
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

    // Collect and display initial names
    details.collectNames();
    details.display();

    // Search for a string
    string str;
    cout << "Enter the string to search: ";
    cin >> str;
    bool ans = details.search(str);
    if (ans)
    {
        cout << "The string is found!" << endl;
    }
    else
    {
        cout << "The string is not found!" << endl;
    }

    // Convert names to uppercase and display again
    details.makeupper();
    details.display();

    return 0;
}
