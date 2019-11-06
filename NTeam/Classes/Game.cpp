//
// Created by Rui Pinto on 10/11/2019.
//

#include "Game.h"
#include <iostream>

#include "../NecessaryFunctions_NameSpaces.h"


using namespace std;

Game::Game(unsigned int id, Date date, string city, string country, string stadium,
           string oppositeTeam, vector<string> oppositeTeamParticipants,
           vector<string> refereeTeam, GameStats *gameStats, vector<Stats *> individualStatistics) {
    this->id = id;
    this->date = date;
    this->country = country;
    this-> stadium = stadium;
    this-> oppositeTeam = oppositeTeam;
    this->oppositeTeamParticipants = oppositeTeamParticipants;
    this->refereeTeam = refereeTeam;
    this->gameStats = gameStats;
    this->individualStatistics = individualStatistics;
}

unsigned int Game::getId() const {
    return id;
}

Date Game::getDate() const {
    return date;
}

string Game::getCity() const {
    return city;
}

string Game::getCountry() const {
    return country;
}

string Game::getStadium() const {
    return stadium;
}

string Game::getOppositeTeam() const {
    return oppositeTeam;
}

vector<string> Game::getOppositeTeamParticipants() const {
    return oppositeTeamParticipants;
}

vector<string> Game::getRefereeTeam() const {
    return refereeTeam;
}

GameStats *Game::getGameStats() const {
    return gameStats;
}

vector<Stats *> Game::getIndividualStatistics() const {
    return individualStatistics;
}

void Game::setId(unsigned int id) {
    this->id = id;
}

void Game::setDate(const Date &date) {
    this->date = date;
}

void Game::setCity(const string &city) {
    this->city = city;
}

void Game::setCountry(const string &country) {
    this->country = country;
}

void Game::setStadium(const string &stadium) {
    this->stadium = stadium;
}

void Game::setOppositeTeam(const std::string &oppositeTeam) {
    this->oppositeTeam = oppositeTeam;
}

void Game::setOppositeTeamParticipants(const vector<string> &oppositeTeamParticipants) {
    this->oppositeTeamParticipants = oppositeTeamParticipants;
}

void Game::setRefereeTeam(const vector<string> &refereeTeam) {
    this->refereeTeam = refereeTeam;
}

void Game::setGameStats(GameStats *gameStats) {
    this->gameStats = gameStats;
}

void Game::setIndividualStatistics(const vector<Stats *> setIndividualStatistics) {
    this->individualStatistics = individualStatistics;
}

// NOT TESTED YET!!!
void Game::info(ostream &os) const {
    os << "Date: " << date << endl;
    os << "City: " << city << endl;
    os << "Country: " << country << endl;
    os << "Stadium: " << stadium << endl;
    os << "Opposite Team: " << oppositeTeam << endl;
    os << "Opposite Team Participants: ";
    generalFunctions::coutVectorString(os ,oppositeTeamParticipants);
    os << endl;
}