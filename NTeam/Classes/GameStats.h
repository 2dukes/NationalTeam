//
// Created by Rui Pinto on 11/5/2019.
//

#ifndef NTEAM_GAMESTATS_H
#define NTEAM_GAMESTATS_H

#include <iostream>

class GameStats {
public:
    /**
     * @brief - Game Statistics Constructor.
     * @param id - Id
     * @param goals - Goals
     * @param oppositionGoals - Opposite Team Goals
     * @param shots - Shots
     * @param oppositionShots - Opposite Team Shots
     * @param shotsTarget - Shots on Target
     * @param oppositionShotsTarget - Opposite Team Shots on Target
     * @param possession - Possession
     * @param passes - Passes
     * @param oppositionPasses - Opposite Team Passes
     * @param passAccuracy - Pass Accuracy
     * @param oppositionPassAccuracy - Opposite Team Pass Accuracy
     * @param fouls - Fouls
     * @param oppositionFouls - Opposite Team Fouls
     * @param offSides - Offsides
     * @param oppositionOffSides - Opposite Team Offsides
     * @param corners - Corners
     * @param oppositionCorners - Opposite Team Corners
     * @param yellowCards - Yellow Cards
     * @param oppositionYellowCards - Opposite Team Yellow Cards
     * @param redCards - Red Cards
     * @param oppositionRedCards - Opposite Team Red Cards
     * @param injuries - Injuries
     * @param oppositionInjuries - Opposite Team Injuries
     */
    GameStats(unsigned int id, unsigned short goals, unsigned short oppositionGoals, unsigned short shots, unsigned short oppositionShots, unsigned short shotsTarget,
              unsigned short oppositionShotsTarget, unsigned short possession, unsigned short passes,
              unsigned short oppositionPasses, unsigned short passAccuracy, unsigned short oppositionPassAccuracy,
              unsigned short fouls, unsigned short oppositionFouls, unsigned short offSides, unsigned short oppositionOffSides,
              unsigned short corners, unsigned short oppositionCorners, unsigned short yellowCards,
              unsigned short oppositionYellowCards, unsigned short redCards, unsigned short oppositionRedCards,
              unsigned short injuries, unsigned short oppositionInjuries);

    /* Gets */
    /**
     *
     * @return - ID
     */
    unsigned int getId() const;
    /**
     *
     * @return - Goals
     */
    unsigned short getGoals() const;
    /**
     *
     * @return - Opposite Team Goals
     */
    unsigned short getOppositionGoals() const;
    /**
     *
     * @return - Shots
     */
    unsigned short getShots() const;
    /**
     *
     * @return - Opposite Team Shots
     */
    unsigned short getOppositionShots() const;
    /**
     *
     * @return - Shots on Target
     */
    unsigned short getShotsTarget() const;
    /**
     *
     * @return - Opposite Team Shots on Target
     */
    unsigned short getOppositionShotsTarget() const;
    /**
     *
     * @return - Possession
     */
    unsigned short getPossession() const;
    /**
     *
     * @return Passes
     */
    unsigned short getPasses() const;
    /**
     *
     * @return - Opposite Team Passes
     */
    unsigned short getOppositionPasses() const;
    /**
     *
     * @return - Pass Accuracy
     */
    unsigned short getPassAccuracy() const;
    /**
     *
     * @return - Opposite Team Pass Accuracy
     */
    unsigned short getOppositionPassAccuracy() const;
    /**
     *
     * @return - Fouls
     */
    unsigned short getFouls() const;
    /**
     *
     * @return - Opposite Team Fouls
     */
    unsigned short getOppositionFouls() const;
    /**
     *
     * @return - Offsides
     */
    unsigned short getOffsides() const;
    /**
     *
     * @return - Opposite Team Offsides
     */
    unsigned short getOppositionOffsides() const;
    /**
     *
     * @return - Corners
     */
    unsigned short getCorners() const;
    /**
     *
     * @return - Opposite Team Corners
     */
    unsigned short getOppositionCorners() const;
    /**
     *
     * @return - Yellow Cards
     */
    unsigned short getYellowCards() const;
    /**
     *
     * @return - Opposite Team Yellow Cards
     */
    unsigned short getOppositionYellowCards() const;
    /**
     *
     * @return - Red Cards
     */
    unsigned short getRedCards() const;
    /**
     *
     * @return - Opposite Team Red Cards
     */
    unsigned short getOppositionRedCards() const;
    /**
     *
     * @return - Injuries
     */
    unsigned short getInjuries() const;
    /**
     *
     * @return - Opposite Team Injuries
     */
    unsigned short getOppositionInjuries() const;

    /* Sets */
    /**
     *
     * @param id - ID
     */
    void setId(unsigned int id);
    /**
     *
     * @param goals - Goals
     */
    void setGoals(unsigned short goals);
    /**
     *
     * @param oppositionGoals - Opposite Team Goals
     */
    void setOppositionGoals(unsigned short oppositionGoals);
    /**
     *
     * @param shots - Shots
     */
    void setShots(unsigned short shots);
    /**
     *
     * @param oppositionShots - Opposite Team Shots
     */
    void setOppositionShots(unsigned short oppositionShots);
    /**
     *
     * @param shotsTarget - Shots on Target
     */
    void setShotsTarget(unsigned short shotsTarget);
    /**
     *
     * @param oppositionShotsTarget - Opposite Team Shots on Target
     */
    void setOppositionShotsTarget(unsigned short oppositionShotsTarget);
    /**
     *
     * @param possession - Possession
     */
    void setPossession(unsigned short possession);
    /**
     *
     * @param passes - Passes
     */
    void setPasses(unsigned short passes);
    /**
     *
     * @param oppositionPasses - Opposite Team Passes
     */
    void setOppositionPasses(unsigned short oppositionPasses);
    /**
     *
     * @param passAccuracy - Pass Accuracy
     */
    void setPassAccuracy(unsigned short passAccuracy);
    /**
     *
     * @param oppositionPassAccuracy - Opposite Team Pass Accuracy
     */
    void setOppositionPassAccuracy(unsigned short oppositionPassAccuracy);
    /**
     *
     * @param fouls - Fouls
     */
    void setFouls(unsigned short fouls);
    /**
     *
     * @param oppositionFouls - Opposite Team Fouls
     */
    void setOppositionFouls(unsigned short oppositionFouls);
    /**
     *
     * @param offsides - Offsides
     */
    void setOffsides(unsigned short offsides);
    /**
     *
     * @param oppositionOffsides - Opposite Team Offsides
     */
    void setOppositionOffsides(unsigned short oppositionOffsides);
    /**
     *
     * @param corners - Corners
     */
    void setCorners(unsigned short corners);
    /**
     *
     * @param oppositionCorners -Opposite Team Corners
     */
    void setOppositionCorners(unsigned short oppositionCorners);
    /**
     *
     * @param yellowCards - Yellow Cards
     */
    void setYellowCards(unsigned short yellowCards);
    /**
     *
     * @param oppositionYellowCards - Opposite Team Yellow Cards
     */
    void setOppositionYellowCards(unsigned short oppositionYellowCards);
    /**
     *
     * @param redCards - Red Cards
     */
    void setRedCards(unsigned short redCards);
    /**
     *
     * @param oppositionRedCards - Opposite Team Red Cards
     */
    void setOppositionRedCards(unsigned short oppositionRedCards);
    /**
     *
     * @param injuries - Injuries
     */
    void setInjuries(unsigned short injuries);
    /**
     *
     * @param oppositionInjuries -Opposite Team Injuries
     */
    void setOppositionInjuries(unsigned short oppositionInjuries);

    /* Other Methods */
    /**
     * @brief - Display Game Statistics Info (horizontal)
     * @param os - Ostream (cout, ofstream)
     */
    void info(std::ostream &os) const;

private:
    /**
     * Game Statistics ID = Game ID
     */
    unsigned int id; // Same ID as The game...
    /*
     * Goals, and opposition goals
     */
    unsigned int goals, oppositionGoals;
    /**
     * asd
     */
    unsigned short shots, oppositionShots;
    unsigned short shotsTarget, oppositionShotsTarget;
    unsigned short possession;
    unsigned short passes, oppositionPasses;
    unsigned short passAccuracy, oppositionPassAccuracy;
    unsigned short fouls, oppositionFouls;
    unsigned short offsides, oppositionOffsides;
    unsigned short corners, oppositionCorners;
    unsigned short yellowCards, oppositionsYellowCards;
    unsigned short redCards, oppositionRedCards;
    unsigned short injuries, oppositionInjuries;
};


#endif //NTEAM_GAMESTATS_H
