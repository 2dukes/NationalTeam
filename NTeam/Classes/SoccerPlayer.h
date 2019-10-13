//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_SOCCERPLAYER_H
#define NTEAM_SOCCERPLAYER_H

#include "Staff.h"
#include "InfCall.h"
#include <map>

class SoccerPlayer: public Staff {
public:
    int getSalary() const;
    int getEnsuranceValue() const;
private:
    std::string position;
    std::string club;
    unsigned short weight;
    unsigned short height;
    unsigned long marketPrice;
    int daysActive;
    bool injured;
    // std::map<Call*, InfCall, Comparer>;
    int ensurance; // Varies depending on daysActive & marketPrice

};


#endif //NTEAM_SOCCERPLAYER_H
