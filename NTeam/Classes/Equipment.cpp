//
// Created by Administrator on 24/12/2019.
//

#include "Equipment.h"

Equipment::Equipment(std::string type, std::string model, Date date) {
    this->id = id;
    this->type = type;
    this->model = model;
    this->date = date;
}

int Equipment::getID() const {

    return id;
}

std::string Equipment::getType() const {

    return type;
}

std::string Equipment::getModel() const {

    return model;
}

Date Equipment::getDate() const {

    return date;
}

void Equipment::setID(unsigned int id) {
    this->id = id;
}

void Equipment::setType(std::string type) {
    this->type = type;
}

void Equipment::setModel(std::string model) {
    this->model = model;
}

void Equipment::setDate(Date date) {
    this->date = date;
}