//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_SOCCERPLAYER_H
#define NTEAM_SOCCERPLAYER_H

#include "Staff.h"
#include "Call.h"
#include <map>


class SoccerPlayer: public Staff {
public:
    SoccerPlayer(unsigned int, std::string name, std::string role, Date birthDate, int salary, std::string position,
            std::string club, unsigned short weight, unsigned short height,
                 unsigned long marketPrice, unsigned int daysActive, bool injured);
    std::string getName() const;
    Date getBirthDay() const;
    int getSalary() const;
    std::string getPosition() const;
    std::string getClub();
    unsigned short getWeight() const;
    unsigned short getHeight() const;
    unsigned long getMarketPrice() const;
    unsigned int getDaysActive() const;
    bool isInjured() const;
    int getEnsuranceValue() const;
private:
    std::string position;
    std::string club;
    unsigned short weight;  // weight in kg
    unsigned short height;  // height in cm
    unsigned long marketPrice;  // market price in €
    unsigned int daysActive;
    bool injured;
    std::vector<Call*> calls;
    int ensurance; // Varies depending on daysActive, marketPrice and injury status

};


#endif //NTEAM_SOCCERPLAYER_H
