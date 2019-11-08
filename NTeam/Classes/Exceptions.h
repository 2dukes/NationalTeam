//
// Created by Rui Pinto on 11/6/2019.
//

#ifndef NTEAM_EXCEPTIONS_H
#define NTEAM_EXCEPTIONS_H

#include <string>

class NoPersonFound {
public:
    NoPersonFound(std::string e): error(e) { }
    std::string getError() { return error; }
private:
    std::string error;
};

class NoStatisticFound {
public:
    NoStatisticFound(std::string e): error(e) { }
    std::string getError() { return error; }
private:
    std::string error;
};


#endif //NTEAM_EXCEPTIONS_H
