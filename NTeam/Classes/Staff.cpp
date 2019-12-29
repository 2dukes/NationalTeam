
#include "Staff.h"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

Staff::Staff(unsigned int i, std::string name, Date birthDate, unsigned int salary, std::string function): id(i), name(name),
                                                    birthDate(birthDate), salary(salary), function(function) {}

/* Gets */

unsigned int Staff::getId() const
{
    return id;
}

string Staff::getName() const
{
    return name;
}

const Date Staff::getDate() const {
    return birthDate;
}

unsigned int Staff::getSalary() const {
    return salary;
}

std::string Staff::getRole() const {
    return function;
}

/* Sets */

void Staff::setName(std::string name)
{
    this->name = name;
}

void Staff::setDate(Date date)
{
    birthDate = date;
}

/* Other Methods */

void Staff::info(std::ostream &os) const
{
    os << "ID: " << id << "\n";
    os << "Name: " << name << "\n";
    os << "Birth Date: " << birthDate << "\n";
}

void Staff::info() const
{
    ostringstream o_stream;
    o_stream << birthDate;
    cout << left << setw(5) << id << left << setw(50) << name <<
         left << setw(15) << o_stream.str();

}

bool Staff::operator==(const Staff &worker) const {
    return id == worker.getId();
}

void Staff::operator=(const Staff &worker) {
    this->id = worker.getId();
    this->function = worker.getRole();
    this->birthDate = worker.getDate();
    this->name = worker.getName();
    this->salary = worker.getSalary();
}




