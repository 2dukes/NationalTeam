#ifndef NTEAM_STAFF_H
#define NTEAM_STAFF_H

#include <string>
#include "Date.h"

/**
 * @brief - Mother Class. It's the base that contains all the common parameters for SoccerPlayer, OtherWorker and TechnicalTeam.
 */
class Staff {
public:
    /**
     * @brief - Staff constructor.
     * @param i - ID
     * @param name - Name
     * @param birthDate - Birth Date
     * @param salary - Salary
     * @param function - Role
     */
    Staff(unsigned int i, std::string name, Date birthDate, unsigned int salary, std::string function);

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
    const Date getDate() const;
    /**
     *
     * @return - Person's Salary
     */
    virtual unsigned int getSalary() const;

    /**
     * @brief - Gets Staff member Role.
     * @return - Itself.
     */
    virtual std::string getRole() const;

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

    /**
     * @brief - Operator that compares if to Staff members are the same.
     * @param worker - Worker it self.
     */
    void operator=(const Staff &worker);


protected:
    /**
     * Person's ID (immutable)
     */
    unsigned int id;
    /**
     * Person's Name
     */
    std::string name;
    /**
     * Person's Birth Date
     */
    Date birthDate;

    /**
     * Salary
     */
    unsigned int salary;

    /**
     * Job.
     */
    std::string function;
};


#endif //NTEAM_STAFF_H
