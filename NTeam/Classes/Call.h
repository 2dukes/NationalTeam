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
    Call(unsigned int id, std::string competition, std::vector<Game*> games, std::vector<InfCall*> infs,
            std::vector<SoccerPlayer*> players, Date begin, Date end, int housing_food);

    /* Gets */
    unsigned int getId() const;
    /* Sets */

private:
    unsigned int id;
    std::string competition; // Friendly, Euro, WorldCup
    std::vector<Game*> games;
    std::vector<InfCall*> infs;
    std::vector<SoccerPlayer*> players; // Jogadores Convocados
    Date begin;
    Date end;
    int housing_food;
};


#endif //NTEAM_CALL_H
