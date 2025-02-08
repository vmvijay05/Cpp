#include "Student.h"
#include <iostream>

// Methods to set student details
void Student::setStudentID(int id) {
    studentID = id;
}

void Student::setName(std::string studentName) {
    name = studentName;
}

void Student::setAge(int studentAge) {
    age = studentAge;
}

void Student::setGrade(double studentGrade) {
    grade = studentGrade;
}

// Methods to get student details
int Student::getStudentID() {
    return studentID;
}

std::string Student::getName() {
    return name;
}

int Student::getAge() {
    return age;
}

double Student::getGrade() {
    return grade;
}

// Method to display student details
void Student::displayDetails() {
    std::cout << "Student ID: " << studentID << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Grade: " << grade << std::endl;
}
