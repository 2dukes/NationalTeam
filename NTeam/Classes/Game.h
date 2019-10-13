//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_GAME_H
#define NTEAM_GAME_H


#include "SoccerPlayer.h"
#include "Stats.h"
#include <vector>

class Game {
public:

private:
    std::string cidade;
    std::string country;
    std::string stadium;
    // Jogadores Convocados -> Jogadores Participantes são os convocados com KMS percorridos

    // std::map<SoccerPlayer*, Stats*, Comparer>;
    Date time;
    std::string refereeTeam; // Or Class...

};


#endif //NTEAM_GAME_H
