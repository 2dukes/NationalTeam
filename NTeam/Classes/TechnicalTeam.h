//
// Created by Rui Pinto on 10/13/2019.
//

#ifndef NTEAM_TECHNICALTEAM_H
#define NTEAM_TECHNICALTEAM_H

#include "Staff.h"

/**
 * @brief - Technical Team members. The class is exactly like the Other Worker. For future implementations might be diferent. It's just a way to distinguish the two of them.
 */
class TechnicalTeam: public Staff {
public:
    /**
     * @brief - TechnicalTeam constructor. (Goalkeeper Coach, Defenders' Coach, Midfielders' Coach, Forwards' Coach, etc)
     * @param id - ID
     * @param role - Function/Role
     * @param sal - Salary
     * @param name - Name
     * @param birth - Birth Date
     */
    TechnicalTeam(unsigned int id, std::string role, unsigned int sal, std::string name, Date birth);

    /* Gets */

    /**
     *
     * @return - Salary
     */
    unsigned int getSalary() const;
    /**
     *
     * @return - Function/Role
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
     * @param role - Function/Role
     */
    void setRole(std::string role);

    /* Other Methods */

    /**
     * Displays TechnicalTeam info (vertically)
     */
    void info() const;
    /**
     * Displays TechnicalTeam information header.
     */
    static void header();

private:
    /**
     * Person's Salary
     */
    unsigned int salary;
    /**
     * Person's Function/Role.
     */
    std::string role;
};


#endif //NTEAM_TECHNICALTEAM_H
