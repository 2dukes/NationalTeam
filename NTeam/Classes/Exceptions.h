//
// Created by Rui Pinto on 11/6/2019.
//

#ifndef NTEAM_EXCEPTIONS_H
#define NTEAM_EXCEPTIONS_H

#include <string>

class NoObjectFound {
public:
    /**
     * @brief - Exception Class invoked whenever there's no corresponding object given a certain search.
     * @param e - Error
     */
    NoObjectFound(std::string e): error(e) { }
    /**
     *
     * @return - Error
     */
    std::string getError() { return error; }
private:
    std::string error;
};

class WrongStatistic {
public:
    /**
     * @brief - Exception Class invoked whenever a wrong statistic is found.
     * @param e - Error
     */
    WrongStatistic(std::string e): error(e) { }
    /**
     *
     * @return - Error
     */
    std::string getError() { return error; }
private:
    std::string error;
};


#endif //NTEAM_EXCEPTIONS_H
