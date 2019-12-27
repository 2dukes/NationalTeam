//
// Created by Administrator on 23/12/2019.
//

#ifndef NTEAM_EQUIPMENT_H
#define NTEAM_EQUIPMENT_H

#include <string>
#include <queue>
#include <iostream>
#include "Date.h"

class Equipment : public Provider{
public:
    Equipment(unsigned int id, std::string type, std::string model, Date date)
    friend void infoE(std::ostream &os, priority_queue<Equipment> &e1) const;
private:
    unsigned int id;
    static unsigned int id_aux;
    std::string type;
    std::string model;
    Date date;
    unsigned short stock;
    priority_queue equipment;


};

#endif //NTEAM_EQUIPMENT_H
