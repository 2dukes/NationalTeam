#ifndef NTEAM_OTHERWORKER_H
#define NTEAM_OTHERWORKER_H

#include "Staff.h"
#include <string>

/**
 * @brief - Other Workers class. Represents the smaller workers working for the whole.
 */
class OtherWorker: public Staff {
public:
    /**
     * @brief - OtherWorker constructor.
     * @param id - OtherWorker ID.
     * @param role - Function.
     * @param sal - Salary
     * @param name - Name
     * @param birth - Birth Date
     */
    OtherWorker(unsigned int id, std::string role, unsigned int sal, std::string name, Date birth);

    /* Gets */

    /**
     *
     * @return - Salary.
     */
    unsigned int getSalary() const;
    /**
     *
     * @return - Function/Role.
     */
    std::string getRole() const;

    /* Sets */

    /**
     *
     * @param salary - Salary
     */
    void setSalary(unsigned int salary);
    /**
     *
     * @param role - Function/Role.
     */
    void setRole(std::string role);

    /* Other Methods */

    /**
     * @brief - Displays OtherWorker info (horizontal)
     * @param os - Ostream (cout, ofstream)
     */
    void info(std::ostream &os) const;
    /**
     * Displays OtherWorker info (vertical)
     * Displays Other Workers' info.
     */
    void info() const;
    /**
     * Displays Other Workers' information header.
     */
    static void header();

private:
    /**
     * Salary.
     */
    unsigned int salary;
    /**
     * Function/Role.
     */
    std::string role;
};


#endif //NTEAM_OTHERWORKER_H
