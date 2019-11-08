//
// Created by Rui Pinto on 10/13/2019.
//

#include <iostream>
#include "TechnicalTeam.h"

TechnicalTeam::TechnicalTeam(unsigned int id, std::string role, unsigned int sal, std::string name, Date birth): Staff(id, name, birth) {
    this->role = role;
    salary = sal;
}

unsigned int TechnicalTeam::getSalary() const {
    return salary;
}

std::string TechnicalTeam::getRole() const {
    return role;
}

void TechnicalTeam::setSalary(unsigned int salary) {
    this->salary = salary;
}

void TechnicalTeam::setRole(std::string) {
    this->role = role;
}

void TechnicalTeam::info(std::ostream &os) const {
    Staff::info(os);
    os << "Role: " << role << "\n";
    os << "Salary: " << salary << "\n";
    os << "\n" << "::::::::::" << "\n\n";
}