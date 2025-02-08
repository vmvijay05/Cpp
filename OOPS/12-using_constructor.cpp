#include <iostream>
#include <string>
using namespace std;

class student
{
private:
    string name;
    int age;

public:
    // The constructor has the same name as the class
    //  Constructor with parameters
    student(string studentname, int studentage)
    {
        name = studentname;
        age = studentage;
    }

    void displayDetails()
    {
        cout << "Student_Name: " << name << ", Age: " << age << endl;
    }
};

int main()
{
    student person1("Vijay", 25);
    student person2("Kumar", 30);

    person1.displayDetails();
    person2.displayDetails();
}
