//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_NATIONALTEAM_H
#define NTEAM_NATIONALTEAM_H

#include <vector>
#include "SoccerPlayer.h"
#include "OtherWorker.h"
#include "Call.h"
#include "Game.h"
#include "../NecessaryFunctions_NameSpaces.h"

class NationalTeam {
public:
    NationalTeam() { };

    /* Gets */
    std::string getName() const;
    const std::vector<Staff*>& getWorkers(); // Inserted...

    /* Sets */
    std::string setName(std::string name); /* Returns string because of menu's 1st option */

    /* OtherMethods */
    bool CreateOtherWorker();
    bool AlterOtherWorker();
    void addWorker(Staff* oW);
    bool deleteWorker();
    bool readOtherWorkersFile(std::string filename);

    Staff* WorkerLookUp();
private:
    std::vector<Staff*> workers; // Technical Team and OtherWorkers
    std::vector<SoccerPlayer*> players;
    std::vector<InfCall*> InfCalls;
    std::vector<Call*> calls;
    std::vector<Game*> games;
    std::string name;
};


#endif //NTEAM_NATIONALTEAM_H
