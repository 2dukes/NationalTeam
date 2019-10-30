#include <iostream>
#include "NationalTeam.h"
#include "menuPresent.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    NationalTeam N;
//    N.CreateOtherWorker();
//    N.WorkerLookUp()->info(std::cout);
//    mainMenu(N);
    Date date(14,6,75);
    Staff* staff = new OtherWorker(214, "Expregada de limpeza", "Maria Lima", date, 5000);
    N.readOtherWorkersFile("../Files/OtherWorkers.txt");
    for (auto &x: N.getWorkers())
        x->info(std::cout);
//    N.CreateOtherWorker();
    return 0;
}