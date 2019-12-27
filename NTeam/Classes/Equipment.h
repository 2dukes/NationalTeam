//
// Created by Administrator on 24/12/2019.
//

#ifndef RANDOM_EQUIPMENT_H
#define RANDOM_EQUIPMENT_H

#include <string>
#include <queue>
#include <iostream>
#include "Date.h"

class Equipment {
public:
    Equipment(unsigned int id, std::string type, std::string model, Date date);
    int getID() const;
    std::string getType() const;
    std::string getModel() const;
    Date getDate() const;
    void setID(unsigned int id);
    void setType(std::string type);
    void setModel(std::string model);
    void setDate(Date date);
    //friend void infoE(std::ostream &os, std::priority_queue<Equipment> &e1);

private:
    unsigned int id;
    static unsigned int id_aux;
    std::string type;
    std::string model;
    Date date;


};
#endif //RANDOM_EQUIPMENT_H
