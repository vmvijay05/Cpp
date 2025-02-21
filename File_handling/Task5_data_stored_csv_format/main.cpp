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

    void writeToCSV(ofstream &out)
    {
        out << serial_num << ","
            << fullname << ","
            << emailid << ","
            << password << ","
            << work_status << ","
            << mobile_num << "\n";
    }

    bool readFromCSV(ifstream &in)
    {
        string line;
        if (!getline(in, line))
            return false;
        size_t pos = 0;
        string token;

        pos = line.find(",");
        serial_num = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find(",");
        fullname = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(",");
        emailid = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(",");
        password = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(",");
        work_status = line.substr(0, pos);
        line.erase(0, pos + 1);

        mobile_num = line;

        return true;
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

    void saveToCSVFile(const string &filename)
    {
        ofstream outFile(filename);
        if (!outFile)
        {
            cout << "Error opening file for writing!\n";
            return;
        }

        outFile << "Serial Number,Full Name,Email ID,Password,Work Status,Mobile Number\n";

        for (int i = 0; i < num_records; i++)
        {
            records[i].writeToCSV(outFile);
        }

        outFile.close();
        cout << "Data saved to CSV file successfully!\n";
    }

    void loadFromCSVFile(const string &filename)
    {
        ifstream inFile(filename);
        if (!inFile)
        {
            cout << "Error opening file for reading!\n";
            return;
        }

        cout << "\nReading from CSV File:\n";

        string header;
        getline(inFile, header);

        int i = 0;
        while (i < 10 && records[i].readFromCSV(inFile))
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
    string filename = "registers.csv";

    manager.getAllDetails();
    manager.saveToCSVFile(filename);
    manager.loadFromCSVFile(filename);
}
