//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_INFCALL_H
#define NTEAM_INFCALL_H

#include "Date.h"

/**
 * @brief - InfCall class. Used to store information about when does a player arrives and lefts the location of a given summon.
 */
class InfCall {
public:
    /**
     * @brief - Player Information in a certain Summon.
     * @param id - Id
     * @param soccerPlayerId - Soccer player ID
     * @param arrived - Date arrived
     * @param left - Date left
     */
    InfCall(unsigned int id, unsigned int soccerPlayerId, Date arrived, Date left);

    /* Gets */

    /**
     *
     * @return - ID
     */
    unsigned int getId();
    /**
     *
     * @return - Soccer Player ID
     */
    unsigned int getSoccerPlayerId();
    /**
     *
     * @return - Date arrived
     */
    Date getDateArrived();
    /**
     *
     * @return - Date left
     */
    Date getDateLeft();

    /* Sets */

    /**
     *
     * @param date - Date arrived
     */
    void setDateArrived(Date date);
    /**
     *
     * @param date - Date left
     */
    void setDateLeft(Date date);

    /* Other Methods */
    /**
     * Display header for player summon information.
     */
    static void header();
    /**
     * Display player summon information.
     */
    void info();
private:
    /**
     * InfCall ID
     */
    unsigned int id;
    /**
     * Soccer Player ID
     */
    unsigned int soccerPlayerId;
    /**
     * Date when soccer player arrived
     */
    Date arrived;
    /**
     * Date when soccer player left
     */
    Date left;
};


#endif //NTEAM_INFCALL_H
