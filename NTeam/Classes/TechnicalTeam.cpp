
#include <iostream>
#include "TechnicalTeam.h"
#include <iomanip>

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

void TechnicalTeam::setRole(std::string role) {
    this->role = role;
}

void TechnicalTeam::info() const {
    Staff::info();
    std::cout << std::left << std::setw(20) << salary << std::left << std::setw(25) << role;
}

void TechnicalTeam::header()
{
    std::cout << std::endl;
    std::cout << std::left << std::setw(5) << "ID" << std::left << std::setw(50) << "Name"<< std::left << std::setw(15) << "Birth Date"
              << std::left << std::setw(20) << "Salary" << std::left << std::setw(25) << "Role" << std::endl;
    std::cout << "===================================================================================================================================================================================================================" << std::endl;
}