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
    Date begin;
    Date end;
    int dailyEnsurance; // Varies depending on marketPrice & injured
    bool injured;
    Date date_injured;
};


#endif //NTEAM_INFCALL_H
