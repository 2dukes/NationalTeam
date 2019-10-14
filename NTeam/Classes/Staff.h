//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_STAFF_H
#define NTEAM_STAFF_H

#include <string>
#include "Date.h"


class Staff { // It will be abstract class
public:
    Staff(unsigned int i, std::string role, std::string name, Date birthDate);
    virtual int getSalary() = 0;
    void info(std::ostream &os) const;
    unsigned int getId() const;
protected:
    unsigned int id;
    std::string role;
    std::string name;
    Date birthDate;
};


#endif //NTEAM_STAFF_H
