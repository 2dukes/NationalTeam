//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_CALL_H
#define NTEAM_CALL_H

#include <vector>
#include "Game.h"
#include "Date.h"
#include "SoccerPlayer.h"
#include "InfCall.h"

class Call {
public:

private:
    unsigned int id;
    std::string competition; // Friendly, Euro, WorldCup
    std::vector<Game*> games;
    std::vector<InfCall*> Infs;
    std::vector<SoccerPlayer*> players; // Jogadores Convocados
    Date begin;
    Date end;
    int housing_food;
};


#endif //NTEAM_CALL_H
