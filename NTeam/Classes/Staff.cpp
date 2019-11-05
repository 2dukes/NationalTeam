//
// Created by Rui Pinto on 10/11/2019.
//

#include "Staff.h"
#include <fstream>

using namespace std;

Staff::Staff(unsigned int i, std::string name, Date birthDate): id(i), name(name), birthDate(birthDate) {}

/* Gets */

unsigned int Staff::getId() const
{
    return id;
}

string Staff::getName() const
{
    return name;
}

Date Staff::getDate() const
{
    return birthDate;
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

void Staff::info(ostream &os) const
{
    os << "ID: " << id << "\n";
    os << "Name: " << name << "\n";
    os << "Birth: " << birthDate << "\n";
}

bool Staff::operator==(const Staff &worker) const {
    return id == worker.getId();
}