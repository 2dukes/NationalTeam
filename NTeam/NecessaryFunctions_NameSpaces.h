
#ifndef NTEAM_NECESSARYFUNCTIONS_NAMESPACES_H
#define NTEAM_NECESSARYFUNCTIONS_NAMESPACES_H

#include <string>
#include <iostream>
#include <limits>
#include <vector>
#include "Classes/Staff.h"

namespace verifyInputs {
    bool verifyString(std::string auxStr);
    bool verifyDate(std::string auxStr);
    bool verifyNumber();
}

namespace readOperations {
    std::string readString(std::string parameter);
    Date readDate(std::string parameter);
    std::string confirmAnswer();

    template <class T> // https://dev-notes.eu/2018/08/c++-namespace-template-functions/
    T readNumber(std::string parameter)
    {
        T auxNum;
        do {
            std::cout << parameter;
            std::cin >> auxNum;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } while(verifyInputs::verifyNumber());
        return auxNum;
    }
}

namespace generalFunctions {
    std::string coutVectorString(const std::vector<std::string> &v);
    void trim(std::string &str);
    std::vector<std::string> separate_string(std::string str, char separator);
    std::vector<int> convert_vector_str_to_int(std::vector<std::string> v);

    template <class T>
    bool inVector(std::vector<T> v, T elem) {
        for (auto &x: v) {
            if (x == elem)
                return true;
        }
        return false;
    }


    /* Date Functions */
    bool leapYear(int year);
    unsigned int numDays(int year, int month);
    bool checkBetweenDates(Date shorter, Date mid, Date higher);
    unsigned int getDays(Date begDate, Date endDate);
}

#endif //NTEAM_NECESSARYFUNCTIONS_NAMESPACES_H
