//
// Created by Rui Pinto on 10/13/2019.
//

#ifndef NTEAM_TECHNICALTEAM_H
#define NTEAM_TECHNICALTEAM_H

#include "Staff.h"

class TechnicalTeam: public Staff {
public:
    // int getSalary() = 0;
private:
    int salary;
    std::string role;
    // Other parameters pending...
};


#endif //NTEAM_TECHNICALTEAM_H
