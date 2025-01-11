#include <iostream>
using namespace std;

class student
{
public:
    string name;
    string company_name;
    int code;
    int age;
    string add;

    bool isadult()
    {
        if (age > 18)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void personaldetail()
    {
        cout << "The student name is" << name << endl;
        cout << "The employee id is" << code << endl;
        cout << "The employee age is" << age << endl;
        cout << "Employee address is:" << add << endl;
    }
    void companydetail()
    {
        cout << "The company name is" << company_name << endl;
        if (isadult() == true)
        {
            cout << "The employee is adult" << endl;
        }
        else
        {
            cout << "The employee is child" << endl;
        }
    }
};

int main()
{
    student studetail;
    studetail.name = "Vijaykumar";
    studetail.age = 16;
    studetail.company_name = "econ";
    studetail.code = 2025;
    studetail.add = "north street";
    studetail.personaldetail();
    studetail.companydetail();
}
