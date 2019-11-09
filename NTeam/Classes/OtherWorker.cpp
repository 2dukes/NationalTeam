#include <iostream>
#include <string>

#include "Staff.h"
#include "OtherWorker.h"
#include <fstream>
#include <iomanip>

using namespace std;

OtherWorker::OtherWorker(unsigned int id, string role, unsigned int sal, string name, Date birth): Staff (id, name, birth)
{
    this->role = role;
    salary = sal;
}

/* Gets */

unsigned int OtherWorker::getSalary() const
{
    return salary;
}

string OtherWorker::getRole() const
{
    return role;
}

/* Sets */

void OtherWorker::setRole(std::string role)
{
    this->role = role;
}

void OtherWorker::setSalary(unsigned int salary) {
    this->salary = salary;
}


/* OtherMethods */

void OtherWorker::info(ostream &os) const
{
    Staff::info(os);
    os << "Function: " << role << "\n";
    os << "Salary: " << salary << "\n";
    os << "\n" << "::::::::::" << "\n\n";
}

void OtherWorker::info() const
{
    Staff::info();
    cout << left << setw(20) << salary << left << setw(25) << role;
}

void OtherWorker::header()
{
    std::cout << std::endl;
    std::cout << std::left << std::setw(5) << "ID" << std::left << std::setw(50) << "Name"<< std::left << std::setw(10) << "Birth Date"
              << std::left << std::setw(20) << "Salary" << std::left << std::setw(25) << "Role" << std::endl;
    std::cout << "===================================================================================================================================================================================================================" << endl;
}
