//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_STATS_H
#define NTEAM_STATS_H

#include <string>

class Stats {
public:

private:
    unsigned short goals;
    unsigned short passes;
    unsigned short kms;
    std::string cards; // Information that could be parsed in the future
    bool injured;
};


#endif //NTEAM_STATS_H
