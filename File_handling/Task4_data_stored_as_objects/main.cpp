#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Class to store student details
class Register
{
public:
    int serial_num;
    string fullname;
    string emailid;
    string password;
    string work_status;
    string mobile_num;

    // Function to take user input
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

    // Function to display student details
    void displayDetails()
    {
        cout << "\nSerial No: " << serial_num
             << "\nFull Name: " << fullname
             << "\nEmail: " << emailid
             << "\nWork Status: " << work_status
             << "\nMobile: " << mobile_num
             << "\n-------------------\n";
    }

    // Function to save object data to file
    void writeToFile(ofstream &out)
    {
        out << serial_num << "\n"
            << fullname << "\n"
            << emailid << "\n"
            << password << "\n"
            << work_status << "\n"
            << mobile_num << "\n"
            << "===\n"; // Separator between objects
    }

    // Function to read object data from file
    bool readFromFile(ifstream &in)
    {
        if (!(in >> serial_num))
            return false; // If no more data, stop reading
        in.ignore();
        getline(in, fullname);
        getline(in, emailid);
        getline(in, password);
        getline(in, work_status);
        getline(in, mobile_num);
        string separator;
        getline(in, separator); // Read separator (===)
        return true;
    }
};

// **Class to Store Multiple Register Objects**
class RegisterManager
{
public:
    Register records[10];
    int num_records;

    // Function to get input for multiple objects
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

    // Function to save all objects to file
    void saveToTextFile(const string &filename)
    {
        ofstream outFile(filename);
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
        cout << "Data saved to text file successfully!\n";
    }

    // Function to load all objects from file
    void loadFromTextFile(const string &filename)
    {
        ifstream inFile(filename);
        if (!inFile)
        {
            cout << "Error opening file for reading!\n";
            return;
        }

        cout << "\nReading from Text File:\n";
        int i = 0;
        while (i < 10 && records[i].readFromFile(inFile))
        {
            records[i].displayDetails();
            i++;
        }
        inFile.close();
    }
};

// **Main function**
int main()
{
    RegisterManager manager;
    string filename = "registers.txt";

    manager.getAllDetails();            // Get details of all students
    manager.saveToTextFile(filename);   // Save to file
    manager.loadFromTextFile(filename); // Load and display from file
}
