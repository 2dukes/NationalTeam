//
// Created by Administrator on 24/12/2019.
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

bool Provider::getAvailability() const {
    return availability;
}

unsigned short Provider::getMade_Purchases() const {
    return made_purchases;
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

void Provider::setMade_Purchases(unsigned short made_purchases) {
    this->made_purchases = made_purchases;
}

bool Provider::operator<(const Provider &p1) const {
    if(availability == p1.getAvailability())
        if(reputation == p1.getReputation())
            if(made_purchases == p1.getMade_Purchases())
                id < p1.getId();
            made_purchases < p1.getMade_Purchases();
        reputation < p1.getReputation();
    availability < p1.getAvailability();
}

bool Provider::operator==(const Provider &p1) const {
    return availability == p1.getAvailability();
}

void Provider::Purchase_Availability() {
    priority_queue aux_provider = purchase_order;
    vector<Provider> vp;
    int rn;
    while(!aux_provider.empty()){
        vp.push_back(aux_provider.top());
        aux_provider.pop();
    }
    for(auto x : vp){
        srand (time(NULL));
        rn = rand() % 100 + 1;
        if(rn % 2 != 0) x.availability = false;
        aux_provider.push(x);
    }
    purchase_order = aux_provider;
}

/*
void Provider::info(std::ostream &os) const {
    os << "ID: " << id << endl;
    os << "Name: " << name << endl;
    os << "Reputation: " << reputation << endl;
    for( it = equipment_list.begin() ; it != equipment_list.end(); ++it){
        os << infoE(os, it) << endl;
    }
    os << "\n" << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
}
*/