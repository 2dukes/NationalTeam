#include <iostream>
#include "NationalTeam.h"
#include "menuPresent.h"

int main() {
    NationalTeam N("National Team");

    N.readCoachesFile("../Files/Coaches.txt");
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
    N.readEquipmentsFile("../Files/Equipment.txt");
    N.readProviderFile("../Files/Providers.txt");



    N.writeEquipmentsFile("../Files/Equipment.txt");

    //N.purchaseEquipment();

    //N.createProvider();

    //N.deleteProvider();

    //N.alterProvider();

    //N.displaySpecificProvider();

    //N.displayAllProviders();

    //N.writeProviderFile("../Files/Providers.txt");

    mainMenu(N);



    return 0;
}