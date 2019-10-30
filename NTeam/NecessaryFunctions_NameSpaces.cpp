#include "NecessaryFunctions_NameSpaces.h"
#include "Classes/Date.h"

#include <string>
#include <iostream>


namespace verifyInputs
{
    bool verifyString(std::string auxStr)
    {
        if (auxStr.empty() || std::cin.eof())
        {
            std::cout << "Invalid Option! Please enter a valid input." << std::endl;
            return true;
        }
        return false;
    }

    bool verifyDate(std::string auxStr)
    {
        try {
            Date birth = Date(auxStr);
            return false;
        }
        catch(Date::WrongDateFormat &e) {
            std::cout << e.input << " does not follow the format (YYYY/MM/DD). Please enter a valid input." << std::endl;
            return true;
        }
    }

    bool verifyNumber()
    {
        if (std::cin.fail() || std::cin.eof())
        {
            std::cerr << "Invalid Option! Please enter a valid input." << std::endl;
            return true;
        }
        return false;
    }
}

namespace getWorkers {
//    Staff* WorkerLookUp()
//    {
//
//    }
}