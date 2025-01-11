
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

//  bool search(string name)
//     {
//         if(name == students)
//         {
//             return true;
//         }
//         else{
//             return false;
//         }

//     }

};

int main()
{
    college details;
   details.addstudent("Vijay",26);
    details.addstudent("kumar",27);
    details.addstudent("Ram",40);
//    int ans= details.search("kumar");
//    if(ans==true)
//    {
//        cout << "The key is present." <<  endl;
//    }
//    else{
//        cout << "The key is not present." <<  endl;
//    }
    
    
}
