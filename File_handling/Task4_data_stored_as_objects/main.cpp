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
        cout << "Enter Serial Number: ";
        cin >> serial_num;
        cin.ignore();

        cout << "Enter Full Name: ";
        getline(cin, fullname);

        cout << "Enter Email ID: ";
        getline(cin, emailid);

        cout << "Enter Password: ";
        getline(cin, password);

        cout << "Enter Work Status: ";
        getline(cin, work_status);

        cout << "Enter Mobile Number: ";
        getline(cin, mobile_num);
    }

    void displayDetails()
    {
        cout << "\nSerial No: " << serial_num
             << "\nFull Name: " << fullname
             << "\nEmail: " << emailid
             << "\nWork Status: " << work_status
             << "\nMobile: " << mobile_num << endl;
    }

    void writeToFile(ofstream &out)
    {
        out.write((char *)this, sizeof(Register));
    }

    bool readFromFile(ifstream &in)
    {
        in.read((char *)this, sizeof(Register));
        return in.gcount() == sizeof(Register);
    }
};

class subclass
{
public:
    Register records[10];
    int num_records;

    void getAllDetails()
    {
        cout << "Enter number of records: ";
        cin >> num_records;
        cin.ignore();

        for (int i = 0; i < num_records; i++)
        {
            cout << "\nEnter details for Register " << i + 1 << ":\n";
            records[i].setDetails();
        }
    }

    void saveToBinaryFile(const string &filename)
    {
        ofstream outFile(filename, ios::binary);
        if (!outFile)
        {
            cout << "Error opening file for writing!\n";
            return;
        }

        for (int i = 0; i < num_records; i++)
        {
            records[i].writeToFile(outFile);
        }

        outFile.close();
        cout << "Data saved to binary file successfully!\n";
    }

    void loadFromBinaryFile(const string &filename)
    {
        ifstream inFile(filename, ios::binary);
        if (!inFile)
        {
            cout << "Error opening file for reading!\n";
            return;
        }

        cout << "\nReading from Binary File:\n";
        int i = 0;
        while (i < 10 && records[i].readFromFile(inFile))
        {
            records[i].displayDetails();
            i++;
        }

        inFile.close();
    }
};

int main()
{
    subclass manager;
    string filename = "registers.dat";

    manager.getAllDetails();
    manager.saveToBinaryFile(filename);
    manager.loadFromBinaryFile(filename);
}
