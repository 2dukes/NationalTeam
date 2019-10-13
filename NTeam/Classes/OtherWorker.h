#ifndef NTEAM_OTHERWORKER_H
#define NTEAM_OTHERWORKER_H

#include "Staff.h"


class OtherWorker: public Staff {
public:
    OtherWorker(std::string r, std::string n, Date d, int sal);
    virtual int info() const;
    virtual int info(std::ostream &o) const;
private:


};


#endif //NTEAM_OTHERWORKER_H
