//
// Created by Rui Pinto on 11/5/2019.
//

#include "GameStats.h"

using namespace std;

GameStats::GameStats(unsigned int id, unsigned short goals, unsigned short oppositionGoals, unsigned short shots,
                     unsigned short oppositionShots, unsigned short shotsTarget,unsigned short oppositionShotsTarget,
                     unsigned short possession, unsigned short passes, unsigned short oppositionPasses,
                     unsigned short passAccuracy, unsigned short oppositionPassAccuracy, unsigned short fouls,
                     unsigned short oppositionFouls, unsigned short offsides, unsigned short oppositionOffsides,
                     unsigned short corners, unsigned short oppositionCorners,
                     unsigned short yellowCards, unsigned short oppositionYellowCards, unsigned short redCards,
                     unsigned short oppositionRedCards, unsigned short injuries, unsigned short oppositionInjuries) {
    this->id = id;
    this->goals = goals;
    this->oppositionGoals = oppositionGoals;
    this->shots = shots;
    this->oppositionShots = oppositionShots;
    this->shotsTarget = shotsTarget;
    this->oppositionShotsTarget = oppositionShotsTarget;
    this->possession = possession;
    this->passes = passes;
    this->oppositionPasses = oppositionPasses;
    this->passAccuracy = passAccuracy;
    this->oppositionPassAccuracy = oppositionPassAccuracy;
    this->fouls = fouls;
    this->oppositionFouls = oppositionFouls;
    this->offsides = offsides;
    this->oppositionOffsides = oppositionOffsides;
    this->corners = corners;
    this->oppositionCorners = oppositionCorners;
    this->yellowCards = yellowCards;
    this->oppositionsYellowCards = oppositionYellowCards;
    this->redCards = redCards;
    this->oppositionRedCards = oppositionRedCards;
    this->injuries = injuries;
    this->oppositionInjuries = oppositionInjuries;
}

unsigned int GameStats::getId() const {
    return id;
}

unsigned short GameStats::getGoals() const {
    return goals;
}

unsigned short GameStats::getOppositionGoals() const {
    return oppositionGoals;
}

unsigned short GameStats::getShots() const {
    return shots;
}

unsigned short GameStats::getOppositionShots() const {
    return oppositionShots;
}

unsigned short GameStats::getShotsTarget() const {
    return shotsTarget;
}

unsigned short GameStats::getOppositionShotsTarget() const {
    return oppositionShotsTarget;
}

unsigned short GameStats::getPossession() const {
    return possession;
}

unsigned short GameStats::getPasses() const {
    return passes;
}

unsigned short GameStats::getOppositionPasses() const {
    return oppositionPasses;
}

unsigned short GameStats::getPassAccuracy() const {
    return passAccuracy;
}

unsigned short GameStats::getOppositionPassAccuracy() const {
    return oppositionPassAccuracy;
}

unsigned short GameStats::getFouls() const {
    return fouls;
}

unsigned short GameStats::getOppositionFouls() const {
    return oppositionFouls;
}

unsigned short GameStats::getOffsides() const {
    return offsides;
}

unsigned short GameStats::getOppositionOffsides() const {
    return oppositionOffsides;
}

unsigned short GameStats::getCorners() const {
    return corners;
}

unsigned short GameStats::getOppositionCorners() const {
    return oppositionCorners;
}

unsigned short GameStats::getYellowCards() const {
    return yellowCards;
}

unsigned short GameStats::getOppositionYellowCards() const {
    return oppositionsYellowCards;
}

unsigned short GameStats::getRedCards() const {
    return redCards;
}

unsigned short GameStats::getOppositionRedCards() const {
    return oppositionRedCards;
}

unsigned short GameStats::getInjuries() const {
    return injuries;
}

unsigned short GameStats::getOppositionInjuries() const {
    return oppositionInjuries;
}

void GameStats::setId(unsigned int id) {
    this->id = id;
}

void GameStats::setGoals(unsigned short goals) {
    this->goals = goals;
}

void GameStats::setOppositionGoals(unsigned short oppositionGoals) {
    this->oppositionGoals = oppositionGoals;
}

void GameStats::setShots(unsigned short shots) {
    this->shots = shots;
}

void GameStats::setOppositionShots(unsigned short oppositionShots) {
    this->oppositionShots = oppositionShots;
}

void GameStats::setShotsTarget(unsigned short shotsTarget) {
    this->shotsTarget = shotsTarget;
}

void GameStats::setOppositionShotsTarget(unsigned short oppositionShotsTarget) {
    this->oppositionShotsTarget = oppositionShotsTarget;
}

void GameStats::setPossession(unsigned short possession) {
    this->possession = possession;
}

void GameStats::setPasses(unsigned short passes) {
    this->passes = passes;
}

void GameStats::setOppositionPasses(unsigned short oppositionPasses) {
    this->oppositionPasses = oppositionPasses;
}

void GameStats::setPassAccuracy(unsigned short passAccuracy) {
    this->passAccuracy = passAccuracy;
}

void GameStats::setOppositionPassAccuracy(unsigned short oppositionPassAccuracy) {
    this->oppositionPassAccuracy = oppositionPassAccuracy;
}

void GameStats::setFouls(unsigned short fouls) {
    this->fouls = fouls;
}

void GameStats::setOppositionFouls(unsigned short oppositionFouls) {
    this->oppositionFouls = oppositionFouls;
}

void GameStats::setOffsides(unsigned short offsides) {
    this->offsides = offsides;
}

void GameStats::setOppositionOffsides(unsigned short oppositionOffsides) {
    this->oppositionOffsides = oppositionOffsides;
}

void GameStats::setCorners(unsigned short corners) {
    this->corners = corners;
}

void GameStats::setOppositionCorners(unsigned short oppositionCorners) {
    this->oppositionCorners = corners;
}

void GameStats::setYellowCards(unsigned short yellowCards) {
    this->yellowCards = yellowCards;
}

void GameStats::setOppositionYellowCards(unsigned short oppositionYellowCards) {
    this->oppositionsYellowCards = oppositionYellowCards;
}

void GameStats::setRedCards(unsigned short reCards) {
    this->redCards = reCards;
}

void GameStats::setOppositionRedCards(unsigned short oppositionRedCards) {
    this->oppositionRedCards = oppositionRedCards;
}

void GameStats::setInjuries(unsigned short injuries) {
    this->injuries = injuries;
}

void GameStats::setOppositionInjuries(unsigned short oppositionInjuries) {
    this->oppositionInjuries = oppositionInjuries;
}

void GameStats::info(ostream &os) const {
    os << "ID: " << id << endl;
    os << "Goals: " << goals << endl;
    os << "Opposing Team Goals: " << oppositionGoals << endl;
    os << "Shots: " << shots << endl;
    os << "Opposing Team Shots: " << oppositionShots << endl;
    os << "Shots on Target: " << shotsTarget << endl;
    os << "Opposing Team Shots on Target: " << oppositionShotsTarget << endl;
    os << "Possession: " << possession << endl;
    os << "Opposing Team Possession: " << 100 - possession << endl;
    os << "Passes: " << passes << endl;
    os << "Opposing Team Passes: " << oppositionPasses << endl;
    os << "Pass Accuracy: " << passAccuracy << endl;
    os << "Opposing Team Pass Accuracy: " << oppositionPassAccuracy << endl;
    os << "Fouls: " << fouls << endl;
    os << "Opposing Team Fouls: " << oppositionFouls << endl;
    os << "Yellow Cards: " << yellowCards << endl;
    os << "Opposing Yellow Cards: " << oppositionsYellowCards << endl;
    os << "Red Cards: " << redCards << endl;
    os << "Opposing Red Cards: " << oppositionRedCards << endl;
    os << "Offsides: " << offsides << endl;
    os << "Opposing Offsides: " << oppositionOffsides << endl;
    os << "Corners: " << corners << endl;
    os << "Opposing Team Corners: " << oppositionCorners << endl;
    os << "Injuries: " << injuries << endl;
    os << "Opposing Team Injuries: " << oppositionInjuries << endl;
    os << "\n" << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
}
