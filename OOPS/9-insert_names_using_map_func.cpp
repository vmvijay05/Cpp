#include <iostream>
#include <string>
#include <map>
using namespace std;

class college
{
public:
map<string, int> students;
    
//  map<string, int> people = { {"John", 32}, {"Adele", 45}, {"Bo", 29} };

  void addstudent(string name,int age)
  {
        students[name] = age;
        cout << "student name: " << name << " and age " << age << endl;
  }
  
  bool search(string name)
  {
     // cout<<"end value: "<< students.end();
       if (students.find(name)!= students.end())
        {
            return true;
        }
        else
        {
            return false;
        }
  }

void deleted()
{
    students.erase("vijay");
}

void display() {
        if (students.empty()) {
            cout << "The map is empty." << endl;
            return;
        }
        for (const auto& pair : students) {
            cout << "Name: " << pair.first << ", Age: " << pair.second << endl;
        }
    }

};

int main()
{
    college details;
    
   details.addstudent("Vijay",26);
    details.addstudent("kumar",27);
//details.addstudent("Vijay",40);
    string search_name="asdfg";
    
    bool answer;
    
    answer=details.search(search_name);
    if(answer==true)
    {
        cout << "The student " <<search_name << " is present" << endl;
    }
    else
    {
        cout << "The student " << search_name << " is not present" << endl;
    }
    
    details.deleted();
    cout << "After deleted" << endl;
    details.display();
 
}
