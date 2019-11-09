//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_INDIVIDUALSTATISTICS_H
#define NTEAM_INDIVIDUALSTATISTICS_H

#include <string>
#include "Date.h"

class IndividualStatistics {
public:
    IndividualStatistics(unsigned int id, unsigned int soccerPlayerID, unsigned short goals, unsigned short assists, unsigned short passes,
                         unsigned short shots, unsigned short shotsTarget, unsigned short travelledDistance,
                         unsigned short playedMinutes, unsigned short yellowCards, unsigned short redCards,
                         unsigned short  fouls, bool injured);

    /* Gets */
    unsigned int getId() const;
    unsigned int getSoccerPlayerID() const;
    unsigned short getGoals() const;
    unsigned short getAssists() const;
    unsigned short getPasses() const;
    unsigned short getShots() const;
    unsigned getShotsTarget() const;
    unsigned short getTravelledDistance() const;
    unsigned short getPlayedMinutes() const;
    unsigned short getYellowCards() const;
    unsigned short getRedCards() const;
    unsigned short getFouls() const;
    bool getInjured() const;

    /* Sets */
    void setSoccerPlayerID(unsigned int soccerPlayerID);
    void setGoals(unsigned short goals);
    void setAssists(unsigned short assists);
    void setPasses(unsigned short passes);
    void setShots(unsigned short shots);
    void setShotsTarget(unsigned short shotsTarget);
    void setTravelledDistance(unsigned short travelledDistance);
    void setPlayedMinutes(unsigned short playedMinutes);
    void setYellowCards(unsigned short yellowCards);
    void setRedCards(unsigned short redCards);
    void setFouls(unsigned short fouls);
    void setInjured(bool injured);


private:
    unsigned int id, soccerPlayerID;
    unsigned short goals;
    unsigned short assists;
    unsigned short passes;
    unsigned short shots, shotsTarget;
    unsigned short travelledDistance; // in km
    unsigned short playedMinutes;
    unsigned short yellowCards, redCards;
    unsigned short fouls;
    bool injured;
};


#endif //NTEAM_INDIVIDUALSTATISTICS_H
