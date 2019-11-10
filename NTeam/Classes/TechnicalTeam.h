//
// Created by Rui Pinto on 10/13/2019.
//

#ifndef NTEAM_TECHNICALTEAM_H
#define NTEAM_TECHNICALTEAM_H

#include "Staff.h"

class TechnicalTeam: public Staff {
public:
    TechnicalTeam(unsigned int id, std::string role, unsigned int sal, std::string name, Date birth);

    /* Gets */
    unsigned int getSalary() const;
    std::string getRole() const;

    /* Sets */
    void setSalary(unsigned int salary);
    void setRole(std::string);

    /* Other Methods */
    void info() const;
    static void header();

private:
    unsigned int salary;
    std::string role;
};


#endif //NTEAM_TECHNICALTEAM_H
