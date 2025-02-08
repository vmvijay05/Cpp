#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    int experience;

public:
    Employee(string empName, int year)
    {
        name = empName;
        experience = year;
    }

    void displayDetails()
    {
        cout << "Employee Name: " << name << endl;
        cout << "Years of Experience: " << experience << endl;
    }
};

int main()
{
    Employee emp1("Vijaykumar", 5);

    emp1.displayDetails();
}
