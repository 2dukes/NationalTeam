
#ifndef NTEAM_EXCEPTIONS_H
#define NTEAM_EXCEPTIONS_H

#include <string>

/**
 * @brief - Exceptions file, used to store exception classes.
 */
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
    /**
     * Error string
     */
    std::string error;
};

/**
 * @brief - Exception Class invoked whenever a wrong statistic is found.
 */
class WrongStatistic {
public:
    /**
     * @brief - WrongStatistic constructor.
     * @param e - Error
     */
    WrongStatistic(std::string e): error(e) { }
    /**
     *
     * @return - Error
     */
    std::string getError() { return error; }
private:
    /**
     * Error string
     */
    std::string error;
};


#endif //NTEAM_EXCEPTIONS_H
