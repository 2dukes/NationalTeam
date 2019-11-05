//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_INFCALL_H
#define NTEAM_INFCALL_H

#include "Date.h"

class InfCall {
private:
    unsigned int id;
    unsigned int SoccerPlayerId;
    std::string playerName;
    Date begin;
    Date end;
    Date injuredStart;
    Date injuredEnd;
    int dailyEnsurance; // Varies depending on marketPrice & injured
};


#endif //NTEAM_INFCALL_H
