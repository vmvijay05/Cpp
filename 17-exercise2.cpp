#include <iostream>
#include <string>
using namespace std;

class Personal
{
private:
    string fatherName;
    string motherName;
    string homeAddress;

public:
    void setFatherName(string fathername)
    {
        fatherName = fathername;
    }

    void setMotherName(string motherName)
    {
        motherName = motherName;
    }

    void setHomeAddress(string homeAddress)
    {
        homeAddress = homeAddress;
    }

    string getFatherName()
    {
        return fatherName;
    }

    string getMotherName()
    {
        return motherName;
    }

    string getHomeAddress()
    {
        return homeAddress;
    }
};

class Employee
{
private:
    Personal personalDetails; // object creation

public:
    void setFatherName(string fatherName)
    {
        personalDetails.setFatherName(fatherName);
    }

    void setMotherName(string motherName)
    {
        personalDetails.setMotherName(motherName);
    }

    void setHomeAddress(string homeAddress)
    {
        personalDetails.setHomeAddress(homeAddress);
    }

    string getFatherName()
    {
        return personalDetails.getFatherName();
    }

    string getMotherName()
    {
        return personalDetails.getMotherName();
    }

    string getHomeAddress()
    {
        return personalDetails.getHomeAddress();
    }
};

int main()
{
    Employee abc;
    abc.setFatherName("Vijay");
    abc.setMotherName("Amma");
    abc.setHomeAddress("North car street");

    string fname = abc.getFatherName();
    cout << "The Father name is: " << fname << endl;

    string mname = abc.getMotherName();
    cout << "The Mother name is: " << mname << endl;

    string address = abc.getHomeAddress();
    cout << "The home address is: " << address << endl;
}


