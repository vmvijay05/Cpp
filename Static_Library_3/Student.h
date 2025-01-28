#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    int studentID;
    std::string name;
    int age;
    double grade;

public:
    // Methods to set and get student details
    void setStudentID(int id);
    void setName(std::string studentName);
    void setAge(int studentAge);
    void setGrade(double studentGrade);

    int getStudentID();
    std::string getName();
    int getAge();
    double getGrade();

    // Method to display student details
    void displayDetails();
};

#endif // STUDENT_H
