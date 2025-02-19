#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Register
{
public:
    int serial_num;
    string fullname;
    string emailid;
    string password;
    string work_status;
    string mobile_num;

    void setDetails()
    {
        cout << "Enter Student details: ";
        cin >> serial_num >> fullname >> emailid >> password >> work_status >> mobile_num;
    }

    void writeToFile(string &filename)
    {
        ofstream outputFile(filename, ios::app);
        if (!outputFile)
        {
            cerr << "Error opening file for writing!" << endl;
            return;
        }

        outputFile << serial_num << fullname << emailid << password << work_status << mobile_num << endl;
        outputFile.close();
        cout << "Data stored successfully!\n";
    //    int flag=1;
    //    if(flag==1)
    //    {
           
    //    }
       
    }
    void readFromFile(string &filename)
    {
        ifstream inputFile(filename);
        if (!inputFile)
        {
            cerr << "Error opening file for reading!" << endl;
            return;
        }
        inputFile.close();
    }

    void deleteData(string& filename) {
        ofstream outFile(filename, ios::trunc);
        if (!outFile) {
            cerr << "Error opening file for deleting!" << endl;
        }
        outFile.close();
        cout << "All data has been deleted\n";
    }

};

int main()
{
    Register detail1,detail2,detail3;
    string filename = "students.txt";
    detail1.setDetails(); 
    detail2.setDetails();
    //detail3.setDetails();

    detail1.writeToFile(filename);
    detail1.readFromFile(filename);

    detail2.writeToFile(filename);
    detail2.readFromFile(filename);

    // detail3.writeToFile(filename);
    // detail3.readFromFile(filename);

}

//Tasks:
// 1. File types. ( text file , binary file)
// 2. Store multiple objects as object.
// 3, add number of objects in the file and then store objects.
// 4. dont use student class, use register class. // firstly try with one class, then try with class inside the class.
// 5. pass by value, pass by reference.
