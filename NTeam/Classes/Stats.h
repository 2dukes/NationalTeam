//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_STATS_H
#define NTEAM_STATS_H

#include <string>
#include "Date.h"

class Stats {
public:

private:
    unsigned int id;
    unsigned int soccerPlayerId;
    std::string playerName;
    unsigned short goals;
    unsigned short assists;
    unsigned short passes;
    unsigned short shots, shotsOnTarget;
    unsigned short travelledDistance;
    unsigned short playedMinutes;
    unsigned short yellowCards, redCards;
    unsigned short fouls;
    bool injured;
};


#endif //NTEAM_STATS_H
