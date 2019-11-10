//
// Created by Rui Pinto on 10/13/2019.
//

#include "Call.h"
#include <iomanip>
#include <iostream>

using namespace std;

Call::Call(unsigned int id, std::string competition, std::vector<Game*> games, std::vector<InfCall*> infs,
           std::vector<SoccerPlayer*> players, Date begin, Date end, unsigned int housing_food)
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

vector<Game*>&  Call::getGames()
{
    return games;
}

vector<SoccerPlayer*>&  Call::getPlayers()
{
    return players;
}

std::vector<InfCall*>& Call::getInfs()
{
    return infs;
}

std::string Call::getCompetition() const {
    return competition;
}


Date Call::getBeginDate() const {
    return begin;
}

Date Call::getEndDate() const {
    return end;
}

unsigned int Call::getHousingFood() const {
    return housing_food;
}

void Call::infoPlayers()
{
    header();
    cout << left << setw(10) << id <<
         left << setw(15) << competition << left << setw(20) << begin.getDate() <<
         left << setw(20) << end.getDate() << left << setw(25) << housing_food << endl << endl;

    cout << "===================================================================================================== Players =====================================================================================================" << std::endl << endl;
    std::cout << std::endl;
    std::cout << std::left << std::setw(5) << "ID" << std::left << std::setw(50) << "Name"<< std::left << std::setw(15) << "Birth Date"
              << std::left << std::setw(15) << "Position" << std::left << std::setw(20) << "Club" << std::left << std::setw(10) << "Weight"
              << std::left << std::setw(10) << "Height" << std::left << setw(10) << "Salary" << std::left <<
              std::setw(20) << "Market Price" << std::left << std::setw(20) << "Days Active" << std::left << std::setw(15) << "Arrived" << std::left << std::setw(15) << "Left" << std::endl;
    std::cout << "===================================================================================================================================================================================================================" << endl;
    for(auto &x: players)
    {

        x->info();
        for(auto &y: infs)
        {
            if(x->getId() == y->getSoccerPlayerId())
            {
                std::cout << std::left << std::setw(15) << y->getDateArrived().getDate() << std::left << std::setw(15) << y->getDateLeft().getDate() << std::endl;
                cout << endl;
                break;
            }
        }
    }
}

void Call::infoGames()
{
    header();
    cout << left << setw(10) << id <<
         left << setw(15) << competition << left << setw(20) << begin.getDate() <<
         left << setw(20) << end.getDate() << left << setw(25) << housing_food << endl << endl;
    cout << endl << endl << "===================================================================================================== Games =====================================================================================================" << std::endl << endl;
    for(auto &x: games)
    {
        x->header();
        x->info();
        cout << endl << endl << "Game Statistics:" << endl << endl;
        x->getGameStats()->info(cout);
        cout << endl << endl;
    }
}

void Call::infoStats()
{

}

void Call::header()
{
    std::cout << std::endl;
    std::cout << std::left << std::setw(10) << "ID" << std::left << std::setw(15) << "Competition"
              << std::left << std::setw(20) << "Begin Date" << std::left << std::setw(20) << "End Date" << std::left << std::setw(25) << "Housing and Food (costs)" << std::endl;
    std::cout << "===================================================================================================================================================================================================================" << std::endl;
}



void Call::setCompetition(std::string competition) {
    this->competition = competition;
}

void Call::setGames(std::vector<Game *> games) {
    this->games = games;
}

void Call::setInfs(std::vector<InfCall *> infs) {
    this->infs = infs;
}

void Call::setPlayers(std::vector<SoccerPlayer *> players) {
    this->players = players;
}

void Call::setBeginDate(Date begin) {
    this->begin = begin;
}

void Call::setEndDate(Date end) {
    this->end = end;
}

void Call::setHousingFood(unsigned int housing_food) {
    this->housing_food = housing_food;
}