
#ifndef NTEAM_PROVIDER_H
#define NTEAM_PROVIDER_H

#include <list>
#include <string>
#include <queue>
#include <iostream>
#include <random>
#include "Equipment.h"

class Provider{

public:
    Provider(unsigned int id, std::string name, std::string equipment_type, unsigned short reputation = 5, unsigned int made_purchases = 0, bool availability = true, unsigned int quantity = 0);
    unsigned int getId() const;
    std::string getName() const;
    unsigned short getReputation() const;
    bool getAvailability() const;
    std::string getEquipmentType() const;
    unsigned getMade_Purchases() const;
    unsigned int getQuantity() const;
    void setId(unsigned int id);
    void setName(std::string name);
    void setReputation(unsigned short reputation);
    void setAvailability(bool availability);
    void setEquipmentType(std::string equipment_type);
    void setMade_Purchases(unsigned short made_purchases);
    void setQuantity(unsigned int quantity);
    void info(std::ostream &os) const;
    bool operator<(const Provider& p1) const;
    bool operator==(const Provider& p1) const;



private:
    unsigned int id, made_purchases, quantity;
    std::string name;
    unsigned short reputation;
    std::string equipment_type;
    bool availability;


};
#endif //NTEAM_PROVIDER_H
