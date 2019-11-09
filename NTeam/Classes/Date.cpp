//
// Created by Rui Pinto on 10/11/2019.
//

#include "Date.h"
#include <sstream>
#include <string>
#include <iostream>
#include "../NecessaryFunctions_NameSpaces.h"

using namespace std;

Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(string date) {

    istringstream Dat(date);
    string dayS, monthS, yearS;
    getline(Dat, dayS, '/');
    getline(Dat, monthS, '/');
    getline(Dat, yearS, '/');

    if(Dat.fail())
        throw WrongDateFormat(date); // Throw exception on error
    else
    {
        try {
            day = (unsigned short)stoi(dayS);
            month = (unsigned short)stoi(monthS);
            year = (unsigned short)stoi(yearS);
        }
        catch(...) {
            throw WrongDateFormat(date);
        }
    }

    /* Check Date Format */
    unsigned int maxDays;
    if (month >= 1 && month <= 12)
    {
        maxDays = generalFunctions::numDays(year, month);
        if (!(day >= 1 && day <= maxDays))
            throw WrongDateFormat(date);
    }
    else
        throw WrongDateFormat(date);

}


Date::Date(unsigned short day, unsigned short month, unsigned year) {

    this->day = day;
    this->month = month;
    this->year = year;
}


unsigned short Date::getDay() const {

    return day;

}

unsigned short Date::getMonth() const {

    return month;

}

unsigned Date::getYear() const {

    return year;

}

string Date::getDate() const
{
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}


void Date::setDay(unsigned short &day) {

    this->day = day;

}
void Date::setMonth(unsigned short &month) {

    this->month = month;

}

void Date::setYear(unsigned &year) {

    this->year = year;

}


ostream& operator<<(ostream& out, const Date & date) {

    out << date.day << "/" << date.month << "/" << date.year;
    return out;
}

bool Date::operator==(const Date &d1) const
{
    return (day == d1.day && month == d1.month && year == d1.year);
}

std::istream &operator>>(istream &in, Date & date) {
    string dateString;
    getline(in, dateString);
    date = Date(dateString);
    return in;
}

bool operator<=(Date &date1, Date &date2)
{
    if(date1.year == date2.year)
    {
        if(date1.month == date2.month)
            return date1.day <= date2.day;
        else
            return date1.month < date2.month;
    }
    else
        return date1.year < date2.year;
}