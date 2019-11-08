//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_STAFF_H
#define NTEAM_STAFF_H

#include <string>
#include "Date.h"


class Staff { // It will be abstract class
public:
    Staff(unsigned int i, std::string name, Date birthDate);

    /* Gets */
    unsigned int getId() const;
    std::string getName() const;
    Date& getDate();
    virtual unsigned int getSalary() const = 0;

    /* Sets */
    void setName(std::string name);
    void setDate(Date date);

    /* Other Methods */
    virtual void info(std::ostream &os) const;

    virtual ~Staff() { };
    bool operator==(const Staff &worker) const;

protected:
    const unsigned int id; // Const because it's immutable
    std::string name;
    Date birthDate;
};


#endif //NTEAM_STAFF_H
