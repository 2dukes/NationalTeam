//
// Created by Rui Pinto on 10/13/2019.
//

#include "Call.h"

Call::Call(unsigned int id, std::string competition, std::vector<Game*> games, std::vector<InfCall*> infs,
           std::vector<SoccerPlayer*> players, Date begin, Date end, int housing_food)
{
    this->id = id;
    this->competition = competition;
    this->games = games;
    this->infs = infs;
    this->players = players;
    this->begin = begin;
    this->end = end;
    this->housing_food = housing_food;
}

unsigned int Call::getId() const
{
    return id;
}