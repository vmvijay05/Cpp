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
        cin >> serial_num;
        cout << "Full Name: ";
        cin >> fullname ;
        cout << "Email ID: ";
        cin>>emailid;
        cout << "Password: ";
        cin>>password;
        cout << "Work Status: ";
        cin>>work_status;
        cout << "Mobile Number: ";
        cin>>mobile_num;
    }

    void writeToFile(string &filename)
    {
        ofstream outputFile(filename, ios::binary | ios::app);
        if (!outputFile)
        {
            cerr << "Error opening file for writing!" << endl;
            return;
        }
        outputFile.write(reinterpret_cast<char *>(this), sizeof(Register));
        outputFile.close();
        cout << "Data stored successfully in binary format!\n";
    }

    void readFromFile(string &filename)
    {
        ifstream inputFile(filename, ios::binary);
        if (!inputFile)
        {
            cerr << "Error opening file for reading!" << endl;
            return;
        }
        Register temp;
        cout << "Reading student data from file:\n";
        while (inputFile.read(reinterpret_cast<char *>(&temp), sizeof(Register)))
        {
            cout << "Serial Number: " << temp.serial_num << endl;
            cout << "Full Name: " << temp.fullname << endl;
            cout << "Email ID: " << temp.emailid << endl;
            cout << "Password: " << temp.password << endl;
            cout << "Work Status: " << temp.work_status << endl;
            cout << "Mobile Number: " << temp.mobile_num << endl;
        }
        inputFile.close();
    }
 
};

int main()
{
    Register detail1, detail2;
    string filename = "students.bin";

    detail1.setDetails();
    detail2.setDetails();
    
    detail1.writeToFile(filename);
    detail2.writeToFile(filename);
    
    cout << "\nRetrieving stored data:\n";
    detail1.readFromFile(filename);
}

