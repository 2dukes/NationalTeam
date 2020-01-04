
#ifndef NTEAM_PROVIDER_H
#define NTEAM_PROVIDER_H

#include <list>
#include <string>
#include <queue>
#include <iostream>
#include <random>
#include "Equipment.h"

/**
 * @brief - Class that represents a Provider of the National Team.
 */
class Provider{

public:
    /**
     * @brief - Provides constructor.
     * @param id - Provider ID
     * @param name - Name
     * @param equipment_type - Equipment Type
     * @param reputation - Rep
     * @param made_purchases - Purchases made
     * @param availability - Availability
     * @param quantity - Quantity
     */
    Provider(unsigned int id, std::string name, std::string equipment_type, unsigned short reputation = 5, unsigned int made_purchases = 0, bool availability = true, unsigned int quantity = 0);

    /**
     * @brief - Gets Provider ID.
     * @return - Itself.
     */
    unsigned int getId() const;

    /**
     * @brief - Gets Provider Name.
     * @return - Itself.
     */
    std::string getName() const;

    /**
     * @brief - Gets Reputation.
     * @return - Itself.
     */
    unsigned short getReputation() const;

    /**
     * @brief - Gets availability.
     * @return - True if it is availabnle, false otherwise.
     */
    bool getAvailability() const;

    /**
     * @brief - Gets equipment type
     * @return - Itself.
     */
    std::string getEquipmentType() const;

    /**
     * @brief - Purchases made.
     * @return - Itself.
     */
    unsigned getMade_Purchases() const;

    /**
     * @brief - Quantity of products.
     * @return - Itself.
     */
    unsigned int getQuantity() const;

    /**
     * @brief - Gets ID
     * @param id - ID
     */
    void setId(unsigned int id);

    /**
     * @brief - Sets Provider name.
     * @param name - Name
     */
    void setName(std::string name);

    /**
     * @brief - Sets Provider reputation.
     * @param reputation - REP
     */
    void setReputation(unsigned short reputation);

    /**
     * @brief - Sets Provider availability.
     * @param availability - Itself.
     */
    void setAvailability(bool availability);

    /**
     * @brief - Sets Equipment Type.
     * @param equipment_type - Itself.
     */
    void setEquipmentType(std::string equipment_type);

    /**
     * @brief - Sets Purchases made.
     * @param made_purchases - Purchases.
     */
    void setMade_Purchases(unsigned short made_purchases);

    /**
     * @brief - Sets Provider Quantity of products.
     * @param quantity - Itself.
     */
    void setQuantity(unsigned int quantity);

    /**
     * @brief - Presents Info about providers.
     * @param os - Ostream (cout, ofstream...)
     */
    void info(std::ostream &os) const;

    /**
     * @brief - Compares if a provider is smaller than other.
     * @param p1 - Provider.
     * @return - True if so, False otherwise.
     */
    bool operator<(const Provider& p1) const;

    /**
     * @brief - Compares if two providers are equal.
     * @param p1 - Provider.
     * @return True if so, False otherwise.
     */
    bool operator==(const Provider& p1) const;



private:
    /**
     * Id
     */
    unsigned int id;
    /**
     * Purchases made.
     */
    unsigned int made_purchases;

    /**
     * Quantity.
     */
    unsigned int quantity;

    /**
     * Provider name.
     */
    std::string name;

    /**
     * Provider Reputation.
     */
    unsigned short reputation;

    /**
     * Equipement type.
     */
    std::string equipment_type;

    /**
     * Availability.
     */
    bool availability;


};
#endif //NTEAM_PROVIDER_H
