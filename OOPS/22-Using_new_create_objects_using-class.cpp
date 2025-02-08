#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int age;

public:
    // Constructor
    Student(string n, int a)
    {
        name = n;
        age = a;
    }

    void display()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main()
{
    // Dynamically allocate memory for an object using the 'new' operator
    Student *student1 = new Student("Alice", 20);
    Student *student2 = new Student("Bob", 22);

    // Call the display function using the pointer
    student1->display();
    student2->display();

    // Free the allocated memory
    delete student1;
    delete student2;

}
