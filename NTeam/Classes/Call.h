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

/**
 * @brief - Summons class. Used to store players summoned, their information about the call and individual statistics, games and game statistics.
 */
class Call {
public:
    /**
     * @brief - Summon constructor.
     * @param id - ID
     * @param competition - Type of competition
     * @param games - Included Games
     * @param infs - Player information about the summon
     * @param players - List of players who participated
     * @param begin - Begin Date
     * @param end - End Date
     * @param housing_food - Accommodation and food costs
     */
    Call(unsigned int id, std::string competition, std::vector<Game*> games, std::vector<InfCall*> infs,
            std::vector<SoccerPlayer*> players, Date begin, Date end, unsigned int housing_food);

    /* Gets */

    /**
     *
     * @return - Summons' ID
     */
    unsigned int getId() const;
    /**
     *
     * @return - Summons' Games
     */
    std::vector<Game*>& getGames();
    /**
     *
     * @return - Summons' players
     */
    std::vector<SoccerPlayer*>& getPlayers();
    /**
     *
     * @return - Summons' player informations
     */
    std::vector<InfCall*>& getInfs();
    /**
     *
     * @return - Summons' begin Date
     */
    Date getBeginDate() const;
    /**
     *
     * @return - Summons' end Date
     */
    Date getEndDate() const;
    /**
     *
     * @return - Summons' accomodation and food costs
     */
    unsigned int getHousingFood() const;
    /**
     *
     * @return - Summons' type of competition
     */
    std::string getCompetition() const;

    /* Sets */

    /**
     *
     * @param competition - Type of competition
     */
    void setCompetition(std::string competition);
    /**
     *
     * @param games - Games vector
     */
    void setGames(std::vector<Game*> games);
    /**
     *
     * @param infs - Players' information
     */
    void setInfs(std::vector<InfCall*> infs);
    /**
     *
     * @param players - Players vector
     */
    void setPlayers(std::vector<SoccerPlayer*> players);
    /**
     *
     * @param begin - Summons' begin Date
     */
    void setBeginDate(Date begin);
    /**
     *
     * @param end - Summons' end Date
     */
    void setEndDate(Date end);
    /**
     *
     * @param housing_food - Accomodation and food costs
     */
    void setHousingFood(unsigned int housing_food);

    /* Other Methods */

    /**
     * Display Header, while printing the Summons' info.
     */
    static void header();
    /**
     * General display content, while printing the Summons' info.
     */
    void info();
    /**
     * Players' display, while printing the Summons' info.
     */
    void infoPlayers();
    /**
     * Games' display, while printing the Summon's info.
     */
    void infoGames();

private:
    /**
     * Summon' ID
     */
    unsigned int id;
    /**
     * Summon' type competition
     */
    std::string competition; // Friendly, Euro, WorldCup
    /**
     * Summon' Games vector
     */
    std::vector<Game*> games;
    /**
     * Summon' players information
     */
    std::vector<InfCall*> infs;
    /**
     * Summoned players
     */
    std::vector<SoccerPlayer*> players; // Jogadores Convocados
    /**
     * Summon' Begin Date
     */
    Date begin;
    /**
     * Summon' End Date
     */
    Date end;
    /**
     * Summon' Accomodation and Food costs per Player
     */
    int housing_food;
};


#endif //NTEAM_CALL_H
