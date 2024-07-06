#include <iostream>
#include <string>

using namespace std;

/* Declaring the Name struct */
struct Name
{
    string first_name;
    string middle_name;
    string last_name;
};

/* Declaring the DateOfBirth struct */
struct DateOfBirth
{
    int day;
    int month;
    int year;  
};

/* Declaring the Address struct */
struct Address
{
    string street;
    string city;
    string country;
};

/* Declaring the Contacts struct */
struct Contacts
{
    int telephone_number;
    int mobile_number;
    string e_mail_address;
};

/* Declaring the Salary struct */
struct Salary
{
    int basic;
    int additional;
    int reductions;
    int taxes;
};


/* Declaring the Emplyee struct */
struct Employee
{
    Name name;
    DateOfBirth date_of_birth;
    Address address;
    Contacts contacts;
    string job;
    Salary Salary;
};

int main(int argc, char const *argv[])
{   
    return 0;
}
