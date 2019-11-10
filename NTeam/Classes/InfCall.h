//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_INFCALL_H
#define NTEAM_INFCALL_H

#include "Date.h"

class InfCall {
public:
    InfCall(unsigned int id, unsigned int soccerPlayerId, Date arrived, Date left);

    /* Gets */
    unsigned int getId();
    unsigned int getSoccerPlayerId();
    Date getDateArrived();
    Date getDateLeft();
    bool getIsInjured();

    /* Sets */
    void setDateArrived(Date date);
    void setDateLeft(Date date);
    void setIsInjured(bool isInjured);

    /* Other Methods */
    static void header();
    void info();
private:
    unsigned int id;
    unsigned int soccerPlayerId;
    Date arrived;
    Date left;
    bool isInjured;
};


#endif //NTEAM_INFCALL_H
