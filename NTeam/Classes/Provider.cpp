

#include "Provider.h"

Provider::Provider(unsigned int id, std::string name, std::string equipment_type, unsigned short reputation,
                   unsigned int made_purchases, bool availability, unsigned int quantity) {
    this->id = id;
    this->name = name;
    this->equipment_type = equipment_type;
    this->reputation = reputation;
    this->made_purchases = made_purchases;
    this->availability = availability;
    this->quantity = quantity;
}

unsigned int Provider::getId() const {
    return id;
}

std::string Provider::getName() const {
    return name;
}

unsigned short Provider::getReputation() const {
    return reputation;
}

bool Provider::getAvailability() const {
    return availability;
}

std::string Provider::getEquipmentType() const {
    return equipment_type;
}

unsigned Provider::getMade_Purchases() const {
    return made_purchases;
}

unsigned int Provider::getQuantity() const {
    return quantity;
}

void Provider::setId(unsigned int id) {
    this->id = id;
}

void Provider::setName(std::string name) {
    this->name = name;
}

void Provider::setReputation(unsigned short reputation) {
    this->reputation = reputation;
}

void Provider::setAvailability(bool availability) {
    this->availability = availability;
}

void Provider::setEquipmentType(std::string equipment_type) {
    this->equipment_type = equipment_type;
}

void Provider::setMade_Purchases(unsigned short made_purchases) {
    this->made_purchases = made_purchases;
}

void Provider::setQuantity(unsigned int quantity) {
    this->quantity = quantity;
}

bool Provider::operator<(const Provider &p1) const {
    if(availability == p1.getAvailability()) {
        if (reputation == p1.getReputation()) {
            if (made_purchases == p1.getMade_Purchases())
                return id < p1.getId();
            else
                return made_purchases < p1.getMade_Purchases();
        }
        else
            return reputation < p1.getReputation();
    }
    else
        return availability < p1.getAvailability();
}

bool Provider::operator==(const Provider &p1) const {
    return id == p1.getId();
}



void Provider::info(std::ostream &os) const {
    os << "ID: " << id << "\n";
    os << "Name: " << name << "\n";
    os << "Type: " << equipment_type << "\n";
    os << "Reputation: " << reputation << "\n";
    os << "Purchases: " << made_purchases << "\n";
    os << "Available: " << availability << "\n";
    os << "Quantity: " << quantity << "\n";
}


