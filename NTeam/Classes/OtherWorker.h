#ifndef NTEAM_OTHERWORKER_H
#define NTEAM_OTHERWORKER_H

#include "Staff.h"
#include <string>


class OtherWorker: public Staff {
public:
    OtherWorker(unsigned int id, std::string role, unsigned int sal, std::string name, Date birth);

    /* Gets */
    unsigned int getSalary() const;
    std::string getRole() const;

    /* Sets */
    void setSalary(unsigned int salary);
    void setRole(std::string role);

    /* Other Methods */
    void info(std::ostream &os) const;
    void info() const;
    static void header();

private:
    unsigned int salary;
    std::string role;
};


#endif //NTEAM_OTHERWORKER_H
