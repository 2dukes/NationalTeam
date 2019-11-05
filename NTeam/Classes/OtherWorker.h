#ifndef NTEAM_OTHERWORKER_H
#define NTEAM_OTHERWORKER_H

#include "Staff.h"
#include <string>


class OtherWorker: public Staff {
public:
    OtherWorker(unsigned int id, std::string role, std::string name, Date birth, float sal);

    /* Gets */
    int getSalary() const;
    std::string getRole() const;

    /* Sets */
    void setSalary(int salary);
    void setRole(std::string role);

    /* Other Methods */
    void info(std::ostream &os) const;

private:
    int salary;
    std::string role;
};


#endif //NTEAM_OTHERWORKER_H
