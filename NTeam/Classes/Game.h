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
    Game(unsigned int id, Date date, std::string city, std::string country, std::string stadium,
         std::string oppositeTeam, std::vector<std::string> oppositeTeamParticipants, std::vector<std::string> refereeTeam,
         GameStats* gameStats, std::vector<IndividualStatistics*> individualStatistics);

    /* Gets */
    unsigned int getId() const;
    Date getDate() const;
    std::string getCity() const;
    std::string getCountry() const;
    std::string getStadium() const;
    std::string getOppositeTeam() const;
    std::vector<std::string> getOppositeTeamParticipants() const;
    std::vector<std::string> getRefereeTeam() const;
    GameStats* getGameStats() const;
    std::vector<IndividualStatistics*> getIndividualStatistics() const;

    /* Sets */
    void setId(unsigned int id);
    void setDate(const Date &date);
    void setCity(const std::string &city);
    void setCountry(const std::string &country);
    void setStadium(const std::string &stadium);
    void setOppositeTeam(const std::string &oppositeTeam);
    void setOppositeTeamParticipants(const std::vector<std::string> &oppositeTeamParticipants);
    void setRefereeTeam(const std::vector<std::string> &refereeTeam);
    void setGameStats(GameStats* gameStats);
    void setIndividualStatistics(const std::vector<IndividualStatistics*> setIndividualStatistics);


    /* OtherMethods */
    void info(std::ostream &os) const;
    static void header();
    void info() const;


private:
    unsigned int id;
    Date date;
    std::string city;
    std::string country;
    std::string stadium;
    std::string oppositeTeam;
    std::vector<std::string> oppositeTeamParticipants;
    // Jogadores Convocados -> Jogadores Participantes são os convocados com KMS percorridos
    std::vector<std::string> refereeTeam;
    GameStats* gameStats;
    std::vector<IndividualStatistics*> individualStatistics;
};


#endif //NTEAM_GAME_H
