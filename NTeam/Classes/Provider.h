//
// Created by Administrator on 24/12/2019.
//

#ifndef RANDOM_PROVIDER_H
#define RANDOM_PROVIDER_H

#include <list>
#include <string>
#include <queue>
#include <iostream>
#include <random>
#include "Equipment.h"

class Provider{

public:
    Provider(unsigned int id, std::string name, bool availability = true, unsigned short reputation = 50, int made_purchases = 0);
    unsigned int getId() const;
    std::string getName() const;
    unsigned short getReputation() const;
    bool getAvailability() const;
    unsigned short getMade_Purchases() const;
    void setId(unsigned int id);
    void setName(std::string name);
    void setReputation(unsigned short reputation);
    void setAvailability(bool availability);
    void setMade_Purchases(unsigned short made_purchases);
    //void addProvider(Provider *p); // FOR NAT_TEAM
    void Purchase_Availability();
    void info(std::ostream &os) const;
    //bool createProvider(); // FOR NAT_TEAM
    bool operator<(const Provider& p1) const;
    bool operator==(const Provider& p1) const;


private:
    unsigned int id;
    std::string name;
    unsigned short reputation;
    int made_purchases;
    std::priority_queue<Provider*> purchase_order; //FOR NAT_TEAM
    bool availability;


};
#endif //RANDOM_PROVIDER_H
