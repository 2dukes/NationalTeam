
#include "SoccerPlayer.h"
#include "../NecessaryFunctions_NameSpaces.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

SoccerPlayer::SoccerPlayer(unsigned int id, std::string name, Date birthDate, std::string position, std::string club,
                           unsigned short weight, unsigned short height, unsigned long marketPrice,
                           unsigned int daysActive): Staff(id, name, birthDate),
                           position(position), club(club), weight(weight), height(height), marketPrice(marketPrice),
                           daysActive(daysActive)
                           { }

/* Gets */

unsigned int SoccerPlayer::getSalary() const {
    return  0.0000005 * marketPrice * daysActive;
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
    os << "\n" << "::::::::::" << "\n\n";
}


void SoccerPlayer::info() const
{
    Staff::info();
    cout << left << setw(15) << position <<
         left << setw(30) << club << left << setw(10) << weight <<
         left << setw(10) << height << left << setw(10) << getSalary() <<
         left << setw(20) << marketPrice <<
         left << setw(20) << daysActive;

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

void SoccerPlayer::header()
{
    std::cout << std::endl;
    std::cout << std::left << std::setw(5) << "ID" << std::left << std::setw(50) << "Name"<< std::left << std::setw(15) << "Birth Date"
              << std::left << std::setw(15) << "Position" << std::left << std::setw(30) << "Club" << std::left << std::setw(10) << "Weight"
              << std::left << std::setw(10) << "Height" << std::left << setw(10) << "Salary" << std::left << std::setw(20) << "Market Price" << std::left << std::setw(10) << "Days Active" << std::endl;
    std::cout << "===================================================================================================================================================================================================================" << endl;
}