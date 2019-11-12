//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_DATE_H
#define NTEAM_DATE_H

#include <string>

class Date {
private:
    /**
     * Date day
     */
    unsigned short day;
    /**
     * Date month
     */
    unsigned short month;
    /**
     * Date year
     */
    unsigned year;

public:
    class WrongDateFormat { // Used for exceptions
    public:
        /**
         * @brief - WrongDateFormat constructor.
         * @param inp - Error
         */
        WrongDateFormat(std::string inp) {input = inp; }
        /**
         * Error variable
         */
        std::string input;
    };
    // Constructors
    /**
     * @brief -Default Date constructor.
     */
    Date(); // Default constructor
    /**
     * @brief - Constructs a Date by giving a string like "12/01/2019" as a parameter.
     * @param date - Date in string format
     */
    Date(std::string date); // constructor from a string date
    /**
     * @brief - Constructs a Date by giving the day, month and year as integer numbers.
     * @param day - Day
     * @param month - Month
     * @param year - Year
     */
    Date(unsigned short day, unsigned short month, unsigned year); // constructor from the separate elements of the date

    // GET methods

    /**
     *
     * @return - Date day
     */
    unsigned short getDay() const;
    /**
     *
     * @return - Date month
     */
    unsigned short getMonth() const;
    /**
     *
     * @return - Date year
     */
    unsigned getYear() const;
    /**
     *
     * @return - Date in string format
     */
    std::string getDate() const; // get the date on the form of a string (day/month/year)

    // SET methods

    /**
     *
     * @param day - Sets Date day
     */
    void setDay(unsigned short &day);
    /**
     *
     * @param month - Sets Date month
     */
    void setMonth(unsigned short &month);
    /**
     *
     * @param year - Sets Date year
     */
    void setYear(unsigned &year);

    // Other methods

    /**
     * @brief - Prints a formatted Date.
     * @param out - Ostream (cout, ofstream)
     * @param date - Date variable
     * @return - Ostream
     */
    friend std::ostream& operator<<(std::ostream& out, const Date & date);

    /**
     * @brief - Reads a Date and converts it into the correct format.
     * @param in - Istream
     * @param date - Date variable
     * @return - Istream
     */
    friend std::istream& operator>>(std::istream& in, Date & date);

    /**
     * @brief Compare two dates.
     * @param d1 - Date to be compared
     * @return true if equal, false otherwise
     */
    bool operator==(const Date &d1) const;
    /**
     * @brief - Compares if a Date is shorter than the other (12/01/2019 <= 15/01/2019 = TRUE).
     * @param date1 - Shorter Date
     * @param date2 - Bigger Date
     * @return - true if date1 <= date2, false otherwise
     */
    friend bool operator<=(Date &date1, Date &date2);

};


#endif //NTEAM_DATE_H
