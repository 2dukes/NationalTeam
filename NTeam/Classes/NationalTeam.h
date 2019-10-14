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
    NationalTeam() { };
    bool CreateOtherWorker();

private:
    std::vector<OtherWorker*> workers;
    std::vector<SoccerPlayer*> players;
    std::vector<InfCall*> InfCalls;
    std::vector<Call*> calls;
    std::vector<Game*> games;
};


#endif //NTEAM_NATIONALTEAM_H
