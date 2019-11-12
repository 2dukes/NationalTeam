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
    unsigned int getSalary() const;
    std::string getPosition() const;
    std::string getClub() const;
    unsigned short getWeight() const;
    unsigned short getHeight() const;
    unsigned long getMarketPrice() const;
    unsigned int getDaysActive() const;

    /* Sets */
    void setPosition(std::string position);
    void setClub(std::string club);
    void setWeight(unsigned short weight);
    void setHeight(unsigned short height);
    void setMarketPrice(unsigned long marketPrice);
    void setDaysActive(unsigned int daysActive);


    /* OtherMethods */
    void info(std::ostream &os) const;
    void info() const;
    static void header();

private:
    std::string position;
    std::string club;
    unsigned short weight;  // weight in kg
    unsigned short height;  // height in cm
    unsigned long marketPrice;  // market price in €
    unsigned int daysActive;
};


#endif //NTEAM_SOCCERPLAYER_H
