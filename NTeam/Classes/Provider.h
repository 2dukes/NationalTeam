//
// Created by Administrator on 23/12/2019.
//

#ifndef NTEAM_PROVIDER_H
#define NTEAM_PROVIDER_H

#include <list>
#include <string>
#include <queue>
#include <iostream>
#include "Equipment.h"

class Provider{

public:
    Provider(unsigned int id, std::string name, unsigned short reputation);
    unsigned int getId() const;
    std::string getName() const;
    unsigned short getReputation() const;
    void setId(unsigned int id);
    void setName(std::string name);
    void setReputation(unsigned short reputation);
    bool createProvider();


private:
    unsigned int id;
    std::string name;
    unsigned short reputation;
    std::list<std::priority_queue<Equipment>> equipment_list;
    bool operator<(const Provider& p1) const;
    bool operator==(const Provider& p1) const;
    void info(std::ostream &os) const;

};

#endif //NTEAM_PROVIDER_H
