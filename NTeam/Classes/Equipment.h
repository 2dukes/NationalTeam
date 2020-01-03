
#ifndef RANDOM_EQUIPMENT_H
#define RANDOM_EQUIPMENT_H

#include <string>
#include <queue>
#include <iostream>
#include "Date.h"

class Equipment {
public:
    Equipment(unsigned int id, std::string type, unsigned int quantity);
    unsigned int getID() const;
    std::string getType() const;
    unsigned int getQuantity() const;
    void setID(unsigned int id);
    void setType(std::string type);
    void setQuantity(unsigned int quantity);

    //friend void infoE(std::ostream &os, std::priority_queue<Equipment> &e1);

private:
    unsigned int id;
    std::string type;
    unsigned int quantity;


};
#endif //RANDOM_EQUIPMENT_H
