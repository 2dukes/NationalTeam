//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_SOCCERPLAYER_H
#define NTEAM_SOCCERPLAYER_H

#include "Staff.h"
#include <map>


class SoccerPlayer: public Staff {
public:
    SoccerPlayer(unsigned int id, std::string name, Date birthDate, std::string position,
            std::string club, unsigned short weight, unsigned short height,
                 unsigned long marketPrice, unsigned int daysActive);

    /* Gets */
    int getSalary() const;
    std::string getPosition() const;
    std::string getClub() const;
    unsigned short getWeight() const;
    unsigned short getHeight() const;
    unsigned long getMarketPrice() const;
    unsigned int getDaysActive() const;

    /* Sets */

    /* OtherMethods */
    void info(std::ostream &os) const;

private:
    std::string position;
    std::string club;
    unsigned short weight;  // weight in kg
    unsigned short height;  // height in cm
    unsigned long marketPrice;  // market price in €
    unsigned int daysActive;
};


#endif //NTEAM_SOCCERPLAYER_H
