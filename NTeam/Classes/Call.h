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
            std::vector<SoccerPlayer*> players, Date begin, Date end, unsigned int housing_food);

    /* Gets */
    unsigned int getId() const;
    std::vector<Game*>& getGames();
    std::vector<SoccerPlayer*>& getPlayers();
    std::vector<InfCall*>& getInfs();
    Date getBeginDate() const;
    Date getEndDate() const;
    unsigned int getHousingFood() const;
    std::string getCompetition() const;

    /* Sets */
    void setCompetition(std::string competition);
    void setGames(std::vector<Game*> games);
    void setInfs(std::vector<InfCall*> infs);
    void setPlayers(std::vector<SoccerPlayer*> players);
    void setBeginDate(Date begin);
    void setEndDate(Date end);
    void setHousingFood(unsigned int housing_food);

    /* Other Methods */
    static void header();
    void infoPlayers();
    void infoGames();
    void infoStats();

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
