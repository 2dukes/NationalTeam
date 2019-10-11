//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_NATIONALTEAM_H
#define NTEAM_NATIONALTEAM_H

#include <vector>
#include "SoccerPlayer.h"
#include "OtherWorker.h"
#include "Call.h"
#include "Game.h"

class NationalTeam {
public:

private:
    std::vector<SoccerPlayer*> players;
    std::vector<OtherWorker> workers;
    std::vector<Call*> calls; // Don't know if it will be removed
    std::vector<Game*> games;
};


#endif //NTEAM_NATIONALTEAM_H
