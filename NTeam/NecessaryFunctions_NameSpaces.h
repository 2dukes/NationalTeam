//
// Created by Rui Pinto on 10/29/2019.
//

#ifndef NTEAM_NECESSARYFUNCTIONS_NAMESPACES_H
#define NTEAM_NECESSARYFUNCTIONS_NAMESPACES_H

#include <string>
#include <iostream>
#include <limits>
#include "Classes/Staff.h"

namespace verifyInputs {
    bool verifyString(std::string auxStr);
    bool verifyDate(std::string auxStr);
    bool verifyNumber();
}

namespace readOperations {
    std::string readString(std::string parameter);
    Date readDate();
    std::string confirmAnswer();

    template <class T> // https://dev-notes.eu/2018/08/c++-namespace-template-functions/
    T readNumber(std::string parameter, T &auxNum)
    {
        do {
            std::cout << parameter;
            std::cin >> auxNum;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } while(verifyInputs::verifyNumber());
        return auxNum;
    }
}

#endif //NTEAM_NECESSARYFUNCTIONS_NAMESPACES_H
