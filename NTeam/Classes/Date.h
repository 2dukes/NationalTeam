//
// Created by Rui Pinto on 10/11/2019.
//

#ifndef NTEAM_DATE_H
#define NTEAM_DATE_H

#include <string>

class Date {
private:
    unsigned short day;
    unsigned short month;
    unsigned year;

public:
    class WrongDateFormat { // Used for exceptions
    public:
        WrongDateFormat(std::string inp) {input = inp; }
        std::string input;
    };
    // Constructors
    Date(); // Default constructor
    Date(std::string date); // constructor from a string date
    Date(unsigned short day, unsigned short month, unsigned year); // constructor from the separate elements of the date

    // GET methods
    unsigned short getDay() const;
    unsigned short getMonth() const;
    unsigned getYear() const;
    std::string getDate() const; // get the date on the form of a string (year/month/day)

    // SET methods

    void setDay(unsigned short &day);
    void setMonth(unsigned short &month);
    void setYear(unsigned &year);

    // other methods

    friend std::ostream& operator<<(std::ostream& out, const Date & date); // overload of operator << (display the formatted date on a ostream)
    friend std::istream& operator>>(std::istream& in, Date & date);

};


#endif //NTEAM_DATE_H
