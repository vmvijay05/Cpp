
#include <iostream>
#include <string>
using namespace std;

class family
{
public:
    string arr[100];
    int count = 0;

    int addname(string name)
    {
        arr[count] = name;
        count++;
        return 1;
    }
    
    int numofnames()
    {
        // count=count+1;
        return count;
    }

    bool search(string temp)
    {
        // cout << "The search string is: " << temp << endl;
        for (int i = 0; i < count; i++)
        {
            // cout << "Comparing with: " << names[i] << endl;
            if (arr[i] == temp)
            {
                cout << "Found the string: " << temp << endl;
                return true;
            }
        }
        return false;
    }

    void display()
    {
        cout << "The array values are:" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    int count = 0;
    family details;
    details.addname("Vijay");
    details.addname("kumar");
    details.addname("Ram");
    int answer = details.search("kumar");
    if (answer == true)
    {
        cout << "The Searched value is present." << endl;
    }
    else
    {
        cout << "The searched value is not present." << endl;
    }

    details.display();
    int ans = details.numofnames();
    cout << "There are " << ans << " names are present";
}
