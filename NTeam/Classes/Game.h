//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_GAME_H
#define NTEAM_GAME_H

#include "Stats.h"
#include "Date.h"
#include "GameStats.h"
#include <vector>

class Game {
public:

private:
    std::string city;
    std::string country;
    std::string stadium;
    std::string oppositeTeam;
    std::vector<std::string> oppositeTeamParticipants;
    // Jogadores Convocados -> Jogadores Participantes são os convocados com KMS percorridos
    std::vector<Stats*> individualStatistics;
    Date time;
    GameStats* gameStats;
    std::string refereeTeam; // Or Class...

};


#endif //NTEAM_GAME_H
