#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    int age;
    int salary;

public:
    void setname(string empname)
    {
        name = empname;
    }

    void setage(int empage)
    {
        age = empage;
    }

    void setsalary(int empsalary)
    {
        if (empsalary > 0)
        {
            salary = empsalary;
        }
        else
        {
            cout << "Please enter valid salary." << endl;
        }
    }

    string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }

    int getSalary()
    {
        return salary;
    }

    void display()
    {
        cout << "Employee Name: " << name << endl;
        cout << "Employee Age: " << age << endl;
        cout << "Employee Salary: " << salary << endl;
    }
};

int main()
{
    Employee emp1;
    emp1.setname("BalaSaravanan");
    emp1.setage(25);
    emp1.setsalary(45000);

    Employee emp2;
    emp2.setname("Vishnu");
    emp2.setage(26);
    emp2.setsalary(57000);

    cout << "The Employee1 Detail is:" << endl;
    emp1.display();

    cout << "The Employee2 Detail is:" << endl;
    emp2.display();
}
