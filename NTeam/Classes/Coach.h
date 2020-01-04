#ifndef NTEAM_COACH_H
#define NTEAM_COACH_H

#include <string>
#include <list>
#include "Date.h"
#include "bst.h"

/**
 * @brief - Interval class that supports both a begin Date and an End Date.
 */
class Interval {
public:
    /**
     * @brief - Default Constructor.
     * @param begin - Begin Date.
     * @param end - End Date.
     */
    Interval(Date begin, Date end);

    /**
     * @brief - Gets Begin Date.
     * @return - Begin Date.
     */
    Date getBeginDate() const;

    /**
     * @brief - Gets End Date.
     * @return - End Date.
     */
    Date getEndDate() const;

    /**
     * @brief - Sets Begin Date.
     * @param begin - Begin Date.
     */
    void setBeginDate(Date begin);

    /**
     * @brief - Sets End Date.
     * @param end - End Date.
     */
    void setEndDate(Date end);
private:
    /**
     * Begin Date
     */
    Date beginD;
    /**
     * End Date
     */
    Date endD;
};

/**
 * @brief - Coach Classe with their corresponding info.
 */
class Coach {
public:
    /**
     * @brief - Defaul Constructor.
     * @param name - Coach name.
     * @param cupsWon - Cups Won by the coach.
     * @param teamsTrained - Teams that he trained and corresponding time.
     */
    Coach(string name, unsigned int cupsWon, std::list<std::pair<std::string, Interval>> teamsTrained);

    /**
     * @brief - Compares if a Coach is 'less' than the other.
     * @param c  - Coach
     * @return - True if so, False otherwise.
     */
    bool operator<(const Coach &c) const;

    /**
     * @brief - Gets Coache's name.
     * @return - Name.
     */
    std::string getName() const;

    /**
     * @brief - Gets Coache's cups won.
     * @return - Cups won.
     */
    unsigned int getCupsWon() const;

    /**
     * @brief - Gets their teams trained and corresponding intervals.
     * @return - The list itself.
     */
    std::list<std::pair<std::string, Interval>> getTeamsTrained() const;

    /**
     * @brief - Sets Coach name.
     * @param name - Name.
     */
    void setName(std::string name);

    /**
     * @brief - Sets cups won.
     * @param cupsWon - Cups won.
     */
    void setCupsWon(unsigned int cupsWon);

    /**
     * @brief - Adds a new trained team.
     * @param toAdd - Trained team to add and corresponding interval.
     * @return - True if succeeded, False otherwise.
     */
    bool addTrainedTeam(std::pair<std::string, Interval> toAdd);

    /**
     * @brief - Removes a trained team.
     * @param toRemove - Trained team to remove.
     * @return - True if succeeded, False otherwise.
     */
    bool removeTrainedTeam(std::pair<std::string, Interval> toRemove);

    /**
     * @brief - Printing header for the Coach class.
     */
    static void header();


private:
    /**
     * Coach name.
     */
    std::string name;
    /**
     * Cups won.
     */
    unsigned int cupsWon;
    /**
     * Teams Trained along with the corresponding interval int Coache's career.
     */
    std::list<std::pair<std::string, Interval>> teamsTrained;
};


#endif //NTEAM_COACH_H
