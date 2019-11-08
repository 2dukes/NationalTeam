#include <iostream>
#include "NationalTeam.h"
#include "menuPresent.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    NationalTeam N;
//    N.readGamesFile("../Files/Games.txt");
//    N.readOtherWorkersFile("../Files/OtherWorkers.txt");
    N.readSoccerPlayersFile("../Files/SoccerPlayers.txt");
//    N.readGameStatisticsFile("../Files/GameStatistics.txt");
//    N.readIndividualStatisticsFile("../Files/IndividualStatistics.txt");
//    N.createCall();
    mainMenu(N);

    return 0;
}