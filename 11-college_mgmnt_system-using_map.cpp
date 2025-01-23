#include <iostream>
#include <string>
#include <map>
using namespace std;

class college
{
public:
    string college_name;
    string address;
    string employee_code;
    map<string, int> students;
    
    // Function to set college details
    void setCollegeDetails(string c_name, string c_address, string emp_code) {
        college_name = c_name;
        address = c_address;
        employee_code = emp_code;
    }

    // Function to display college details
    void displayCollegeDetails() {
        cout << "College Name: " << college_name << endl;
        cout << "Address: " << address << endl;
        cout << "Employee Code: " << employee_code << endl;
    }

    // Function to add student details
    void addstudent(string name, int age) {
        students[name] = age;
        cout << "Student name: " << name << " and age: " << age << endl;
    }

    // Function to search for a student
    bool search(string name) {
        if (students.find(name) != students.end()) {
            return true;
        } else {
            return false;
        }
    }

    // Function to delete a student by name
    void deleted(string name) {
        students.erase(name);
    }

    // Function to display all students
    void display() {
        if (students.empty()) {
            cout << "No students available." << endl;
            return;
        }
        for (const auto& pair : students) {
            cout << "Name: " << pair.first << ", Age: " << pair.second << endl;
        }
    }
};

int main() {
    college details;

    // Setting college details
    details.setCollegeDetails("ABC College", "123 College St", "EMP1234");

    // Displaying college details
    details.displayCollegeDetails();

    // Adding students
    details.addstudent("Vijay", 26);
    details.addstudent("Kumar", 27);

    // Searching for a student
    string search_name = "Vijay";
    bool answer = details.search(search_name);
    if (answer == true) {
        cout << "The student " << search_name << " is present" << endl;
    } else {
        cout << "The student " << search_name << " is not present" << endl;
    }

    // Deleting a student
    details.deleted("Vijay");

    // Displaying all students
    details.display();

}






