#include "NecessaryFunctions_NameSpaces.h"
#include "Classes/NationalTeam.h"

#include <string>


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
            std::cout << "Invalid Option! Please enter a valid input." << std::endl;
            return true;
        }
        return false;
    }
}

namespace readOperations {
    std::string readString(std::string parameter)
    {
        std::string auxStr;
        do
        {
            std::cout << parameter;
            getline(std::cin, auxStr);
        } while(verifyInputs::verifyString(auxStr));
        return auxStr;
    }

    Date readDate()
    {
        std::string auxBirth;
        do
        {
            std::cout << "Birth Date (YYYY/MM/DD):";
            getline(std::cin, auxBirth);

        } while(verifyInputs::verifyDate(auxBirth));
        return Date(auxBirth);
    }

    std::string confirmAnswer()
    {
        std::string answer;
        while(true)
        {
            getline(std::cin, answer);
            if(answer == "Y" || answer == "y" || answer == "N" || answer == "n")
                break;
            std::cout << "Invalid Option! Please enter a valid input." << std::endl;
        }
        return answer;
    }

}