#ifndef NTEAM_OTHERWORKER_H
#define NTEAM_OTHERWORKER_H

#include "Staff.h"


class OtherWorker: public Staff {
public:
    OtherWorker(unsigned int id, std::string role, std::string name, Date birth, float sal);

    /* Gets */
    float getSalary() const;

    /* Sets */
    void setSalary(float salary);

    /* Other Methods */
    void info(std::ostream &os) const;
private:
    float salary;
};


#endif //NTEAM_OTHERWORKER_H
