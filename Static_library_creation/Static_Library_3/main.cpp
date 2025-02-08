#include <iostream>
#include "Student.h"

int main()
{
    // Create two Student objects
    Student student1;
    Student student2;

    // Set details for Student 1
    student1.setStudentID(101);
    student1.setName("Alice Johnson");
    student1.setAge(20);
    student1.setGrade(89.5);

    // Set details for Student 2
    student2.setStudentID(102);
    student2.setName("Bob Smith");
    student2.setAge(22);
    student2.setGrade(76.3);

    // Display details for Student 1
    std::cout << "Details of Student 1:" << std::endl;
    student1.displayDetails();
    std::cout << std::endl;

    // Display details for Student 2
    std::cout << "Details of Student 2:" << std::endl;
    student2.displayDetails();
    std::cout << std::endl;

    // Update details for Student 1
    student1.setAge(21);
    student1.setGrade(91.2);

    std::cout << "Updated Details of Student 1:" << std::endl;
    student1.displayDetails();

    return 0;
}
