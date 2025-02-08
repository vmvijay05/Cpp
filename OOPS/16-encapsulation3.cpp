#include <iostream>
#include <string>
using namespace std;

class Personal
{
public:
    string fatherName;
    string motherName;
    string homeAddress;
};

class Employee
{
private:
    Personal personalDetails; // object creation

    // getter, setter.
public:
    void setfatherName(string fatheraname)
    {
        personalDetails.fatherName = fatheraname;
    }

    void setmotherName(string mothername)
    {
        personalDetails.motherName = mothername;
    }

    void sethomeaddress(string homeaddress)
    {
        personalDetails.homeAddress = homeaddress;
    }

    string getfathername()
    {
        return personalDetails.fatherName;
    }

    string getmotherName()
    {
        return personalDetails.motherName;
    }

    string gethomeaddress()
    {
        return personalDetails.homeAddress;
    }
};

int main()
{
    Employee personalDetails;
    personalDetails.setfatherName("Vijay");
    personalDetails.setmotherName("Amma");
    personalDetails.sethomeaddress("North car street");

    string fname = personalDetails.getfathername();
    cout << "The Father name is: " << fname << endl;

    string mname = personalDetails.getmotherName();
    cout << "The Mother name is: " << mname << endl;

    string address = personalDetails.gethomeaddress();
    cout << "The home address is: " << address << endl;
}

