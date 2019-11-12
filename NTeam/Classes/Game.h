//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_GAME_H
#define NTEAM_GAME_H

#include "IndividualStatistics.h"
#include "Date.h"
#include "GameStats.h"
#include <vector>

class Game {
public:
    /**
     * @brief - Game Constructor.
     * @param id - Game ID
     * @param date - Game Date
     * @param city - City
     * @param country - Country
     * @param stadium - Stadium Name
     * @param oppositeTeam - Opposite Team
     * @param oppositeTeamParticipants - Opposite Team Participants
     * @param refereeTeam - Referee Team
     * @param gameStats - Game Statistics Pointer
     * @param individualStatistics - Individual Player Statistics Vector
     */
    Game(unsigned int id, Date date, std::string city, std::string country, std::string stadium,
         std::string oppositeTeam, std::vector<std::string> oppositeTeamParticipants, std::vector<std::string> refereeTeam,
         GameStats* gameStats, std::vector<IndividualStatistics*> individualStatistics);

    /* Gets */
    /**
     *
     * @return - Game ID
     */
    unsigned int getId() const;
    /**
     *
     * @return - Game Date
     */
    Date getDate() const;
    /**
     *
     * @return - City
     */
    std::string getCity() const;
    /**
     *
     * @return - Country
     */
    std::string getCountry() const;
    /**
     *
     * @return - Stadium name
     */
    std::string getStadium() const;
    /**
     *
     * @return - Opposite Team
     */
    std::string getOppositeTeam() const;
    /**
     *
     * @return - Opposite Team participants
     */
    std::vector<std::string> getOppositeTeamParticipants() const;
    /**
     *
     * @return - Referee Team
     */
    std::vector<std::string> getRefereeTeam() const;
    /**
     *
     * @return - Pointer to Game Statistics
     */
    GameStats* getGameStats() const;
    /**
     *
     * @return - Individual Statistics vector
     */
    std::vector<IndividualStatistics*> getIndividualStatistics() const;

    /* Sets */

    /**
     *
     * @param id - Game ID
     */
    void setId(unsigned int id);
    /**
     *
     * @param date - Game Date
     */
    void setDate(const Date &date);
    /**
     *
     * @param city - City
     */
    void setCity(const std::string &city);
    /**
     *
     * @param country - Country
     */
    void setCountry(const std::string &country);
    /**
     *
     * @param stadium - Stadium
     */
    void setStadium(const std::string &stadium);
    /**
     *
     * @param oppositeTeam - Opposite Team
     */
    void setOppositeTeam(const std::string &oppositeTeam);
    /**
     *
     * @param oppositeTeamParticipants - Opposite Team Participants
     */
    void setOppositeTeamParticipants(const std::vector<std::string> &oppositeTeamParticipants);
    /**
     *
     * @param refereeTeam - Referee Team
     */
    void setRefereeTeam(const std::vector<std::string> &refereeTeam);
    /**
     *
     * @param gameStats - Game Statistics
     */
    void setGameStats(GameStats* gameStats);
    /**
     *
     * @param setIndividualStatistics - Individual Statistics
     */
    void setIndividualStatistics(const std::vector<IndividualStatistics*> setIndividualStatistics);


    /* OtherMethods */

    /**
     * @brief - Display information about a game (horizontal)
     * @param os - Ostream (cout, ofstream)
     */
    void info(std::ostream &os) const;
    /**
     * Display the header of the Game before printing it's real content.
     */
    static void header();
    /**
     * Display information about a game (vertical)
     */
    void info() const;


private:
    /**
     * Game ID
     */
    unsigned int id;
    /**
     * Game Date
     */
    Date date;
    /**
     * City
     */
    std::string city;
    /**
     * Country
     */
    std::string country;
    /**
     * Stadium
     */
    std::string stadium;
    /**
     * Opposite Team
     */
    std::string oppositeTeam;
    /**
     * Opposite Team Participants
     */
    std::vector<std::string> oppositeTeamParticipants;
    // Jogadores Convocados -> Jogadores Participantes são os convocados com KMS percorridos
    /**
     * Referee Team
     */
    std::vector<std::string> refereeTeam;
    /**
     * Game Statistics
     */
    GameStats* gameStats;
    /**
     * Players' Individual Statistics vector
     */
    std::vector<IndividualStatistics*> individualStatistics;
};


#endif //NTEAM_GAME_H
