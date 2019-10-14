#ifndef NTEAM_OTHERWORKER_H
#define NTEAM_OTHERWORKER_H

#include "Staff.h"


class OtherWorker: public Staff {
public:
    OtherWorker(unsigned int id, std::string role, std::string name, Date birth, int sal);
    int getSalary();
    void info(std::ostream &os) const;
//    virtual int info(std::ostream &o) const;
private:
    int salary;
};


#endif //NTEAM_OTHERWORKER_H
