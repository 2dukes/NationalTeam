//
// Created by Rui Pinto on 10/11/2019.
//

#include "InfCall.h"

InfCall::InfCall(unsigned int id, unsigned int soccerPlayerId, Date arrived, Date left){
    this->id = id;
    this->soccerPlayerId = soccerPlayerId;
    this->arrived = arrived;
    this->left = left;
}

unsigned int InfCall::getId()
{
    return id;
}


unsigned int InfCall::getSoccerPlayerId()
{
    return soccerPlayerId;
}

Date InfCall::getDateArrived()
{
    return arrived;
}

Date InfCall::getDateLeft()
{
    return left;
}

void InfCall::setDateArrived(Date date)
{
    arrived = date;
}

void InfCall::setDateLeft(Date date)
{
    left = date;
}