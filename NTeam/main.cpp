#include <iostream>
#include "NationalTeam.h"
#include "menuPresent.h"

int main() {
    NationalTeam N("National Team");

    N.readTechnicalTeamFile("../Files/TechnicalTeam.txt");
    N.readOtherWorkersFile("../Files/OtherWorkers.txt");
    N.readSoccerPlayersFile("../Files/SoccerPlayers.txt");
    N.readGameStatisticsFile("../Files/GameStatistics.txt");
    N.readIndividualStatisticsFile("../Files/IndividualStatistics.txt");
    N.readGamesFile("../Files/Games.txt");
    N.readInfCalls("../Files/InfCalls.txt");
    N.readCallsFile("../Files/Calls.txt");
    N.readStaffHashTableFile("../Files/StaffHashTable.txt");
    N.addAllTheStaffToHashTable();

    //N.searchOldStaff();

    //N.displayOldStaff();

    N.hireOldStaff();

    //mainMenu(N);

    return 0;
}