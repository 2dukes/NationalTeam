//
// Created by Rui Pinto on 10/11/2019.
//

#include "Staff.h"
#include <fstream>

using namespace std;

Staff::Staff(unsigned int i, std::string role, std::string name, Date birthDate): id(i), role(role),
    name(name), birthDate(birthDate) {}

void Staff::info(ostream &os) const
{
    os << "ID: " << id << "\n";
    os << "Name: " << name << "\n";
    os << "Birth: " << birthDate << "\n";
    os << "Role: " << role << "\n";
}

unsigned int Staff::getId() const
{
    return id;
}