//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_STAFF_H
#define NTEAM_STAFF_H

#include <string>
#include "Date.h"

/**
 * @brief - Mother Class. It's the base that contains all the common parameters for SoccerPlayer, OtherWorker and TechnicalTeam.
 */
class Staff { // It will be abstract class
public:
    /**
     * @brief - Staff constructor.
     * @param i - ID
     * @param name - Name
     * @param birthDate - Birth Date
     */
    Staff(unsigned int i, std::string name, Date birthDate);

    /* Gets */

    /**
     *
     * @return - ID
     */
    unsigned int getId() const;
    /**
     *
     * @return - Name
     */
    std::string getName() const;
    /**
     *
     * @return - Birth Date
     */
    Date& getDate();
    /**
     *
     * @return - Person's Salary
     */
    virtual unsigned int getSalary() const = 0;

    /* Sets */

    /**
     *
     * @param name - Name
     */
    void setName(std::string name);
    /**
     *
     * @param date - Birth Date
     */
    void setDate(Date date);

    /* Other Methods */

    /**
     * @brief - Displays Staff info (horizontal).
     * @param os - Ostream (cout, info)
     */
    virtual void info(std::ostream &os) const;
    /**
     * @brief - Displays Staff info (vertical).
     */
    virtual void info() const;

    /**
     * Staff destructor. Critical when deleting derived classes. It must be virtual otherwise there will be memory pending.
     */
    virtual ~Staff() { };
    /**
     * @brief - Compare two Persons (by ID).
     * @param worker - Person itself.
     * @return - True if they're the same. False otherwise.
     */
    bool operator==(const Staff &worker) const;

protected:
    /**
     * Person's ID (immutable)
     */
    const unsigned int id;
    /**
     * Person's Name
     */
    std::string name;
    /**
     * Person's Birth Date
     */
    Date birthDate;
};


#endif //NTEAM_STAFF_H
