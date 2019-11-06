//
// Created by Rui Pinto on 10/11/2019.
//

#include "SoccerPlayer.h"
#include <iostream>
#include <fstream>

using namespace std;

SoccerPlayer::SoccerPlayer(unsigned int id, std::string name, Date birthDate, std::string position, std::string club,
                           unsigned short weight, unsigned short height, unsigned long marketPrice,
                           unsigned int daysActive): Staff(id, name, birthDate),
                           position(position), club(club), weight(weight), height(height), marketPrice(marketPrice),
                           daysActive(daysActive)
                           { }

/* Gets */

unsigned int SoccerPlayer::getSalary() const {
    return  0.0000001 * marketPrice * daysActive;
}

string SoccerPlayer::getPosition() const {
    return position;
}

string SoccerPlayer::getClub() const {
    return club;
}

unsigned short SoccerPlayer::getWeight() const {
    return weight;
}

unsigned short SoccerPlayer::getHeight() const {
    return height;
}

unsigned long SoccerPlayer::getMarketPrice() const {
    return marketPrice;
}

unsigned int SoccerPlayer::getDaysActive() const {
    return daysActive;
}

/* Other Methods */

void SoccerPlayer::info(std::ostream &os) const {
    Staff::info(os);
    os << "Position: " << position << "\n";
    os << "Club: " << club << "\n";
    os << "Weight: " << weight << "\n";
    os << "Height: " << height << "\n";
    os << "Market Price: " << marketPrice << "\n";
    os << "Days Active: " << daysActive << "\n";
    if(os.rdbuf() == std::cout.rdbuf()) // http://www.cplusplus.com/reference/ios/ios/rdbuf/
        os << "Insurance: " << getSalary() << "\n";
    os << "\n" << "::::::::::" << "\n\n";
}

void SoccerPlayer::setPosition(std::string position) {
    this->position = position;
}

void SoccerPlayer::setClub(std::string club) {
    this->club = club;
}

void SoccerPlayer::setWeight(unsigned short weight) {
    this->weight = weight;
}

void SoccerPlayer::setHeight(unsigned short height) {
    this->height = height;
}

void SoccerPlayer::setMarketPrice(unsigned long marketPrice) {
    this->marketPrice = marketPrice;
}

void SoccerPlayer::setDaysActive(unsigned int daysActive) {
    this->daysActive = daysActive;
}
