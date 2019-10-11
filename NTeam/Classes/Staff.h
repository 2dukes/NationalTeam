//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_STAFF_H
#define NTEAM_STAFF_H

#include <string>
#include "Date.h"


class Staff { // It will be abstract class
public:
    // int getSalary() = 0;
private:
    std::string role;
    std::string name;
    Date birthDate;
};


#endif //NTEAM_STAFF_H
