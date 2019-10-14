//
// Created by Rui Pinto on 10/11/2019.
//

#include "SoccerPlayer.h"


SoccerPlayer::SoccerPlayer(unsigned int id, std::string name, std::string role, Date birthDate, int salary, std::string position, std::string club,
                           unsigned short weight, unsigned short height, unsigned long marketPrice,
                           unsigned int daysActive, bool injured): Staff(id, role, name, birthDate),
                           position(position), club(club), weight(weight), height(height), marketPrice(marketPrice),
                           daysActive(daysActive), injured(injured)
                           { }

int SoccerPlayer::getEnsuranceValue() const {
    if (injured)
        return 0.0000001 * marketPrice * daysActive * 3;
    return 0.0000001 * marketPrice * daysActive;
}
