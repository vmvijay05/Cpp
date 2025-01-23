#include <iostream>
using namespace std;

class Student
{
private:
    string name; // Private member to store the name
    int age;     // Private member to store the age

public:
    // Setter methods to set values (write access)
    void setName(string studentName)
    {
        name = studentName;
    }

    void setAge(int studentAge)
    {
        if (studentAge > 0)
        {
            age = studentAge;
        }
        else
        {
            cout << "Age must be positive." << endl;
        }
    }

    // Getter methods to get values (read access)
    string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }
};

int main()
{
    Student student;
    student.setName("Vijay Kumar");
    student.setAge(27);
    cout << "Student Name: " << student.getName() << endl;
    cout << "Student Age: " << student.getAge() << endl;
}
