//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_INDIVIDUALSTATISTICS_H
#define NTEAM_INDIVIDUALSTATISTICS_H

#include <string>
#include "Date.h"

class IndividualStatistics {
public:
    /**
     * @brief - Individual Statistics Constructor.
     * @param id - ID
     * @param soccerPlayerID - Corresponding soccer player ID
     * @param goals - Goals
     * @param assists - Assists
     * @param passes - Passes
     * @param shots - Shots
     * @param shotsTarget- Shots on Target
     * @param travelledDistance - Travelled Distance
     * @param playedMinutes - Played Minutes
     * @param yellowCards - Yellow Cards
     * @param redCards - Red Cards
     * @param fouls - Fouls
     * @param injured - Injured (true | false)
     */
    IndividualStatistics(unsigned int id, unsigned int soccerPlayerID, unsigned short goals, unsigned short assists, unsigned short passes,
                         unsigned short shots, unsigned short shotsTarget, unsigned short travelledDistance,
                         unsigned short playedMinutes, unsigned short yellowCards, unsigned short redCards,
                         unsigned short  fouls, bool injured);

    /* Gets */
    /**
     *
     * @return - ID
     */
    unsigned int getId() const;
    /**
     *
     * @return - soccer player corresponding ID
     */
    unsigned int getSoccerPlayerID() const;
    /**
     *
     * @return - Goals
     */
    unsigned short getGoals() const;
    /**
     *
     * @return - Assists
     */
    unsigned short getAssists() const;
    /**
     *
     * @return - Passes
     */
    unsigned short getPasses() const;
    /**
     *
     * @return - Shots
     */
    unsigned short getShots() const;
    /**
     *
     * @return - Shots on Target
     */
    unsigned getShotsTarget() const;
    /**
     *
     * @return - Travelled Distance
     */
    unsigned short getTravelledDistance() const;
    /**
     *
     * @return - Played Minutes
     */
    unsigned short getPlayedMinutes() const;
    /**
     *
     * @return - Yellow Cards
     */
    unsigned short getYellowCards() const;
    /**
     *
     * @return - Red Cards
     */
    unsigned short getRedCards() const;
    /**
     *
     * @return - Fouls
     */
    unsigned short getFouls() const;
    /**
     *
     * @return - Injured (true | false)
     */
    bool getInjured() const;

    /* Sets */

    /**
     *
     * @param soccerPlayerID - Soccer player ID
     */
    void setSoccerPlayerID(unsigned int soccerPlayerID);
    /**
     *
     * @param goals - Goals
     */
    void setGoals(unsigned short goals);
    /**
     *
     * @param assists - Assists
     */
    void setAssists(unsigned short assists);
    /**
     *
     * @param passes - Passes
     */
    void setPasses(unsigned short passes);
    /**
     *
     * @param shots - Shots
     */
    void setShots(unsigned short shots);
    /**
     *
     * @param shotsTarget - Shots on Target
     */
    void setShotsTarget(unsigned short shotsTarget);
    /**
     *
     * @param travelledDistance - Travelled Distance
     */
    void setTravelledDistance(unsigned short travelledDistance);
    /**
     *
     * @param playedMinutes - Played Minutes
     */
    void setPlayedMinutes(unsigned short playedMinutes);
    /**
     *
     * @param yellowCards - Yellow Cards
     */
    void setYellowCards(unsigned short yellowCards);
    /**
     *
     * @param redCards - Red Cards
     */
    void setRedCards(unsigned short redCards);
    /**
     *
     * @param fouls - Fouls
     */
    void setFouls(unsigned short fouls);
    /**
     *
     * @param injured - Injured (true | false)
     */
    void setInjured(bool injured);

    /* Other Methods */

    /**
     * Display Individual Statistics' header.
     */
    void header();

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
