//
// Created by Rui Pinto on 11/5/2019.
//

#ifndef NTEAM_GAMESTATS_H
#define NTEAM_GAMESTATS_H


class GameStats {
public:

private:
    unsigned int id;
    unsigned int goals, oppositionGoals;
    unsigned short shots, oppositionShots;
    unsigned short shotsTarget, oppositionShotsTarget;
    unsigned short possession, oppositionPossession;
    unsigned short passes, oppositionPasses;
    unsigned short passAccuracy, oppositionPassAccuracy;
    unsigned short fouls, oppositionFouls;
    unsigned short offsides, oppositionOffsides;
    unsigned short corners, oppositionCorners;
    unsigned short yellowCards, oppositionsYellowCards;
    unsigned short redCards, oppositionsRedCards;
    unsigned short injuries, oppositionsinjuries;
};


#endif //NTEAM_GAMESTATS_H
