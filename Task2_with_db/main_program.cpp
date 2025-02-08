#include <iostream>
#include <cstring>
#include <mysql/mysql.h>
#include "./mysql.h"
#include "./includes/mysql.h"
#include <mysql/field_types.h>
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
    string fathername;
    string emailid;
    string password;
    string phonenumber;

    sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();
    sql::Connection *con = driver->connect("tcp://localhost:3306/Register", "root", "root"); // Updated for localhost
    sql::PreparedStatement *pstmt = con->prepareStatement("INSERT INTO person_details (Fullname, Email_id, Password, Work_status, Mobile_num) VALUES (?, ?, ?, ?,?)");


    bool addItems(string name, string faname, string email, string pin, string mobile)
    {
        fullname = name;
        fathername = faname;
        emailid = email;
        password = pin;
        phonenumber = mobile;

        //database connection:
        sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();

    }
};

int main()
{
    Register user;

    bool result = user.addItems("Vijayakumar", "Manikandan", "iamvichu@gmail.com", "qwert", "7402124473");
    if (result == true)
    {
    }
    else
    {
    }
}
