
#include "Equipment.h"

Equipment::Equipment(unsigned int id, std::string type, unsigned int quantity) {
    this->id = id;
    this->type = type;
    this->quantity = quantity;
}

unsigned int Equipment::getID() const {

    return id;
}

std::string Equipment::getType() const {

    return type;
}

unsigned int Equipment::getQuantity() const {

    return quantity;
}

void Equipment::setID(unsigned int id) {
    this->id = id;
}

void Equipment::setType(std::string type) {
    this->type = type;
}

void Equipment::setQuantity(unsigned int quantity) {
    this->quantity = quantity;
}