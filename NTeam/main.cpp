#include <iostream>
#include "NationalTeam.h"
#include "menuPresent.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    NationalTeam N;
    N.readOtherWorkersFile("../Files/OtherWorkers.txt");
    mainMenu(N);

    return 0;
}