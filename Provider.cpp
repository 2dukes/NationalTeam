//
// Created by Administrator on 23/12/2019.
//

#include "Provider.h"

Provider::Provider(unsigned int id, std::string name, unsigned short reputation) {
    this->id = id;
    this->name = name;
    this->reputation = reputation;
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

void Provider::setId(unsigned int id) {
    this->id = id;
}

void Provider::setName(std::string name) {
    this->name = name;
}

void Provider::setReputation(unsigned short reputation) {
    this->reputation = reputation;
}

bool Provider::operator<(const Provider &p1) const {
    if(reputation == p1.getReputation()) return id < p1.getId();
    return reputation < p1.getReputation();
}

bool Provider::operator==(const Provider &p1) const {
    return  reputation == p1.getReputation();
}

void Provider::info(std::ostream &os) const {
    os << "ID: " << id << endl;
    os << "Name: " << name << endl;
    os << "Reputation: " << reputation << endl;
    for( it = equipment_list.begin() ; it != equipment_list.end(); ++it){
        os << infoE(os, it) << endl;
    }
    os << "\n" << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
}