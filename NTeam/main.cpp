#include <iostream>
#include "NationalTeam.h"
#include "menuPresent.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    NationalTeam N;
    N.readSoccerPlayersFile("../Files/SoccerPlayers.txt");
    N.readOtherWorkersFile("../Files/OtherWorkers.txt");

    return 0;
}