#include <iostream>
#include <string>

#include "Staff.h"
#include "OtherWorker.h"
#include <fstream>

using namespace std;

OtherWorker::OtherWorker(unsigned int id, string role, string name, Date birth, float sal): Staff (id, name, birth)
{
    this->role = role;
    salary = sal;
}

/* Gets */

int OtherWorker::getSalary() const
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

void OtherWorker::setSalary(int salary) {
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


