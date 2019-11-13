//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_SOCCERPLAYER_H
#define NTEAM_SOCCERPLAYER_H

#include "Staff.h"
#include <map>

/**
 * @brief - SoccerPlayer class. Represents the Soccer Players that are part of the National Team.
 */
class SoccerPlayer: public Staff {
public:
    /**
     * @brief - SoccerPlayer constructor
     * @param id - SoccerPlayer ID
     * @param name - Name
     * @param birthDate - Birth Date
     * @param position - Position
     * @param club - Club
     * @param weight - Weight
     * @param height - Height
     * @param marketPrice - Market Price
     * @param daysActive - Number of active days on the National Team.
     */
    SoccerPlayer(unsigned int id, std::string name, Date birthDate, std::string position,
            std::string club, unsigned short weight, unsigned short height,
                 unsigned long marketPrice, unsigned int daysActive);

    /* Gets */

    /**
     *
     * @return - Insurance / Salary value (given by a simple formula)
     */
    unsigned int getSalary() const;
    /**
     *
     * @return - Position
     */
    std::string getPosition() const;
    /**
     *
     * @return - Club
     */
    std::string getClub() const;
    /**
     *
     * @return - Weight
     */
    unsigned short getWeight() const;
    /**
     *
     * @return - Height
     */
    unsigned short getHeight() const;
    /**
     *
     * @return - Market Price
     */
    unsigned long getMarketPrice() const;
    /**
     *
     * @return - Days Active
     */
    unsigned int getDaysActive() const;

    /* Sets */

    /**
     *
     * @param position - Position
     */
    void setPosition(std::string position);
    /**
     *
     * @param club - Club
     */
    void setClub(std::string club);
    /**
     *
     * @param weight - Weight
     */
    void setWeight(unsigned short weight);
    /**
     *
     * @param height - Height
     */
    void setHeight(unsigned short height);
    /**
     *
     * @param marketPrice - Market Price
     */
    void setMarketPrice(unsigned long marketPrice);
    /**
     *
     * @param daysActive - Days Active
     */
    void setDaysActive(unsigned int daysActive);


    /* OtherMethods */

    /**
     * @brief - Displays SoccerPlayer info (horizontal).
     * @param os - Ostream (cout, ofstream)
     */
    void info(std::ostream &os) const;
    /**
     * @brief - Displays OtherWorker info (vertical).
     */
    void info() const;
    /**
     * Displays Soccer Players information header.
     */
    static void header();

private:
    /**
     * Position
     */
    std::string position;
    /**
     * Club
     */
    std::string club;
    /**
     * Weight
     */
    unsigned short weight;
    /**
     * Height
     */
    unsigned short height;
    /**
     * Market Price
     */
    unsigned long marketPrice;
    /**
     * Days Active
     */
    unsigned int daysActive;
};


#endif //NTEAM_SOCCERPLAYER_H
