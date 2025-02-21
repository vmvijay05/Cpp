#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Register
{
public:
    class OfficialInfo
    {
    public:
        int serial_num;
        string emailid;
        string password;
        string work_status;

        void setOfficialInfo()
        {
            cout << "Enter Serial Number: ";
            cin >> serial_num;
            cin.ignore();
            cout << "Enter Email ID: ";
            getline(cin, emailid);
            cout << "Enter Password: ";
            getline(cin, password);
            cout << "Enter Work Status: ";
            getline(cin, work_status);
        }

        void displayOfficialInfo()
        {
            cout << "\nSerial No: " << serial_num
                 << "\nEmail: " << emailid
                 << "\nWork Status: " << work_status;
        }
    };

    string fullname;
    string mobile_num;
    OfficialInfo official;

    void setDetails()
    {
        cout << "Enter Full Name: ";
        getline(cin, fullname);
        cout << "Enter Mobile Number: ";
        getline(cin, mobile_num);
        official.setOfficialInfo();
    }

    void displayDetails()
    {
        cout << "\nFull Name: " << fullname
             << "\nMobile: " << mobile_num;
        official.displayOfficialInfo();
        cout << endl;
    }

    void writeToCSV(ofstream &out)
    {
        out << fullname << ","
            << mobile_num << ","
            << official.serial_num << ","
            << official.emailid << ","
            << official.password << ","
            << official.work_status << "\n";
    }

    bool readFromCSV(ifstream &in)
    {
        string line;
        if (!getline(in, line))
            return false;
        size_t pos = 0;

        pos = line.find(",");
        fullname = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(",");
        mobile_num = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(",");
        official.serial_num = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find(",");
        official.emailid = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(",");
        official.password = line.substr(0, pos);
        line.erase(0, pos + 1);

        official.work_status = line;

        return true;
    }
};

class Subclass
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

        outFile << "Full Name,Mobile Number,Serial Number,Email ID,Password,Work Status\n";

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
    Subclass manager;
    string filename = "registers.csv";

    manager.getAllDetails();
    manager.saveToCSVFile(filename);
    manager.loadFromCSVFile(filename);
}