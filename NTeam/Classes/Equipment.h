
#ifndef RANDOM_EQUIPMENT_H
#define RANDOM_EQUIPMENT_H

#include <string>
#include <queue>
#include <iostream>
#include "Date.h"

/**
 * @brief - Class That represents an equipment.
 */
class Equipment {
public:
    /**
     * @brief - Classe default constructor.
     * @param id - Equipment ID
     * @param type - Equipment Type
     * @param quantity - Equipment quantity.
     */
    Equipment(unsigned int id, std::string type, unsigned int quantity);

    /**
     * @brief - Gets equipment ID.
     * @return - Itself.
     */
    unsigned int getID() const;

    /**
     * @brief - Gets equipment Type.
     * @return - Itself.
     */
    std::string getType() const;

    /**
     * @brief - Gets Equipement Quantity.
     * @return - Itself.
     */
    unsigned int getQuantity() const;

    /**
     * @brief - Set equipment ID.
     * @param id - Itself.
     */
    void setID(unsigned int id);

    /**
     * @brief - Sets equipment type.
     * @param type - Itself.
     */
    void setType(std::string type);

    /**
     * @brief - Sets equipment quantity.
     * @param quantity - Itself.
     */
    void setQuantity(unsigned int quantity);

    //friend void infoE(std::ostream &os, std::priority_queue<Equipment> &e1);

private:
    /**
     * Equipment ID.
     */
    unsigned int id;

    /**
     * Equipment Type.
     */
    std::string type;

    /**
     * Equipment Quantity.
     */
    unsigned int quantity;


};
#endif //RANDOM_EQUIPMENT_H
