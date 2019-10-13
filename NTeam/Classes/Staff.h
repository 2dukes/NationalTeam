//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_STAFF_H
#define NTEAM_STAFF_H

#include <string>
#include "Date.h"


class Staff { // It will be abstract class
public:
    virtual int getSalary() = 0;

protected:
    std::string role;
    std::string name;
    Date birthDate;
    int salary;
};


#endif //NTEAM_STAFF_H
