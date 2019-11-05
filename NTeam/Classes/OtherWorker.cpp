#include <iostream>
#include <string>

#include "Staff.h"
#include "OtherWorker.h"
#include <fstream>

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
    os << "Role: " << role << "\n";
    os << "Salary: " << salary << "\n";
    os << "\n" << "::::::::::" << "\n\n";
}


