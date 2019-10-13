//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_CALL_H
#define NTEAM_CALL_H

#include <vector>
#include "Game.h"

class Call {
public:

private:
    std::vector<Game*> games;
    Date begin;
    Date end;
    int id;
    int housing_food;
};


#endif //NTEAM_CALL_H
