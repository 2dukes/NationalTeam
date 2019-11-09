//
// Created by Rui Pinto on 11/5/2019.
//

#ifndef NTEAM_GAMESTATS_H
#define NTEAM_GAMESTATS_H

#include <iostream>

class GameStats {
public:
    GameStats(unsigned int id, unsigned short goals, unsigned short oppositionGoals, unsigned short shots, unsigned short oppositionShots, unsigned short shotsTarget,
              unsigned short oppositionShotsTarget, unsigned short possession, unsigned short passes,
              unsigned short oppositionPasses, unsigned short passAccuracy, unsigned short oppositionPassAccuracy,
              unsigned short fouls, unsigned short oppositionFouls, unsigned short offSides, unsigned short oppositionOffSides,
              unsigned short corners, unsigned short oppositionCorners, unsigned short yellowCards,
              unsigned short oppositionYellowCards, unsigned short redCards, unsigned short oppositionRedCards,
              unsigned short injuries, unsigned short oppositionInjuries);

    /* Gets */
    unsigned int getId() const;
    unsigned short getGoals() const;
    unsigned short getOppositionGoals() const;
    unsigned short getShots() const;
    unsigned short getOppositionShots() const;
    unsigned short getShotsTarget() const;
    unsigned short getOppositionShotsTarget() const;
    unsigned short getPossession() const;
    unsigned short getPasses() const;
    unsigned short getOppositionPasses() const;
    unsigned short getPassAccuracy() const;
    unsigned short getOppositionPassAccuracy() const;
    unsigned short getFouls() const;
    unsigned short getOppositionFouls() const;
    unsigned short getOffsides() const;
    unsigned short getOppositionOffsides() const;
    unsigned short getCorners() const;
    unsigned short getOppositionCorners() const;
    unsigned short getYellowCards() const;
    unsigned short getOppositionYellowCards() const;
    unsigned short getRedCards() const;
    unsigned short getOppositionRedCards() const;
    unsigned short getInjuries() const;
    unsigned short getOppositionInjuries() const;

    /* Sets */
    void setId(unsigned int id);
    void setGoals(unsigned short goals);
    void setOppositionGoals(unsigned short oppositionGoals);
    void setShots(unsigned short shots);
    void setOppositionShots(unsigned short oppositionShots);
    void setShotsTarget(unsigned short shotsTarget);
    void setOppositionShotsTarget(unsigned short oppositionShotsTarget);
    void setPossession(unsigned short possession);
    void setPasses(unsigned short passes);
    void setOppositionPasses(unsigned short oppositionPasses);
    void setPassAccuracy(unsigned short passAccuracy);
    void setOppositionPassAccuracy(unsigned short oppositionPassAccuracy);
    void setFouls(unsigned short fouls);
    void setOppositionFouls(unsigned short oppositionFouls);
    void setOffsides(unsigned short offsides);
    void setOppositionOffsides(unsigned short oppositionOffsides);
    void setCorners(unsigned short corners);
    void setOppositionCorners(unsigned short oppositionCorners);
    void setYellowCards(unsigned short yellowCards);
    void setOppositionYellowCards(unsigned short oppositionYellowCards);
    void setRedCards(unsigned short reCards);
    void setOppositionRedCards(unsigned short oppositionRedCards);
    void setInjuries(unsigned short injuries);
    void setOppositionInjuries(unsigned short oppositionInjuries);

    /* Other Methods */
    void info(std::ostream &os) const;

private:
    unsigned int id; // Same ID as The game...
    unsigned int goals, oppositionGoals;
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
