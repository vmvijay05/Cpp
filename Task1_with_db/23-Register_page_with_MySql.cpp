#include <iostream>
#include <cstring>
/// #include <string>
#include <mysql/mysql.h>
#include "./mysql.h"
#include "./includes/mysql.h"
#include <mysql/field_types.h>
// #include <../mysql_driver.h>
#include "/usr/include/mysql-cppconn/jdbc/mysql_driver.h"
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
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

    void queryRegisterByEmailID(const string &email);
};

void Register::queryRegisterByEmailID(const string &email)
{

    try
    {


        sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();
        sql::Connection *con = driver->connect("tcp://localhost:3306/Register", "root", "root"); // Updated for localhost
        sql::PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM person_details WHERE Email_ID = ?");
        pstmt->setString(1, email);
        cout << "given email is: " << email << endl;

        sql::ResultSet *res = pstmt->executeQuery();

        if (res->next())
        {
            this->serial_num = res->getInt("Serial_num");
            this->fullname = res->getString("Fullname");
            this->emailid = res->getString("Email_id");
            this->password = res->getString("Password");
            this->work_status = res->getString("Work_status");
            this->mobile_num = res->getString("Mobile_num");
        }
        else
        {
            cout << "No user found with email: " << email << endl;
        }

        delete res;
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException &e)
    {
        cout << "SQLException: " << e.what() << endl;
    }
    cout << "The output object is: " << this->serial_num << endl;
    cout << "The output object is: " << this->fullname << endl;
    cout << "The output object is: " << this->emailid << endl;
    cout << "The output object is: " << this->password << endl;
    cout << "The output object is: " << this->work_status << endl;
    cout << "The output object is: " << this->mobile_num << endl;
}


int main()
{
    Register reg;

    reg.fullname = "venkat";
    reg.emailid = "venkatvgl@gmail.com";
    reg.password = "avcd";
    reg.work_status = "Work";
    reg.mobile_num = "0987654321";

    reg.queryRegisterByEmailID("Vijayvgl@gmail.com");

    try
    {
        sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();
        sql::Connection *con = driver->connect("tcp://localhost:3306/Register", "root", "root"); // Updated for localhost
        sql::PreparedStatement *pstmt = con->prepareStatement("INSERT INTO person_details (Fullname, Email_id, Password, Work_status, Mobile_num) VALUES (?, ?, ?, ?,?)");

       // pstmt->setInt(1, reg.serial_num);
        pstmt->setString(1, reg.fullname);
        pstmt->setString(2, reg.emailid);
        pstmt->setString(3, reg.password);
        pstmt->setString(4, reg.work_status);
        pstmt->setString(5, reg.mobile_num);

        pstmt->execute();
        cout << "Record inserted successfully!" << endl;

        delete pstmt;
        delete con;
    }
    catch (sql::SQLException &e)
    {
        cout << "SQLException: " << e.what() << endl;
    }
}
