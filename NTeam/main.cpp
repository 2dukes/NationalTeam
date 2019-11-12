#include <iostream>
#include "NationalTeam.h"
#include "menuPresent.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    NationalTeam N("National Team");
//    N.readGamesFile("../Files/Games.txt");
    N.readTechnicalTeamFile("../Files/TechnicalTeam.txt");
    N.readOtherWorkersFile("../Files/OtherWorkers.txt");
    N.readSoccerPlayersFile("../Files/SoccerPlayers.txt");
    N.readGameStatisticsFile("../Files/GameStatistics.txt");
    N.readIndividualStatisticsFile("../Files/IndividualStatistics.txt");
    N.readGamesFile("../Files/Games.txt");
    N.readInfCalls("../Files/InfCalls.txt");
    N.readCallsFile("../Files/Calls.txt");
//    N.displayCallsPlayers();
//    N.createCall();
//    N.displaySoccerPlayers();
//    N.displayOtherWorkers();
//    N.getPlayerTotalCost();
//    N.getTeamTotalCost();
//    N.getNationalTeamTotalCost();
//    N.getMonthlyPlayerTotalCost();
//    N.getMonthlyNationalTeamTotalCost();
//    system("pause");
//    N.displayCallsGames();
//    N.writeCallsFile("../Files/Calls.txt");
    mainMenu(N);
//    N.createCall();
    return 0;
}