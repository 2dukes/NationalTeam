#include "NecessaryFunctions_NameSpaces.h"
#include "Classes/NationalTeam.h"

#include <string>
#include <iomanip>

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
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

    Date readDate(std::string parameter)
    {
        std::string auxBirth;
        do
        {
            std::cout << parameter;
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

namespace generalFunctions {
    std::string coutVectorString(const std::vector<std::string> &v) {
        std::string str = "";
        for (auto it = v.begin(); it != v.end() - 1; it++) {
            str += *it + ", ";
        }
        str += v.at(v.size() - 1);
        return str;
    }

    void trim(std::string &str) {
        size_t pos = str.find_first_not_of(' ');
        str.erase(0, pos);
        pos = str.find_last_not_of(' ');
        if (std::string::npos != pos)
            str.erase(pos + 1);
    }

    std::vector<std::string> separate_string(std::string str, char separator) {
        std::vector<std::string> str_fields;
        std::string temp = "";
        str += separator;

        for(size_t i = 0; i < str.size(); i++){
            if (str[i] == separator){
                trim(temp);
                str_fields.push_back(temp);
                temp = "";
            } else {
                temp += str[i];
            }
        }

        return str_fields;
    }

    std::vector<int> convert_vector_str_to_int(std::vector<std::string> v) {
        std::vector<int> vec;
        std::string temp;
        for (size_t i = 0; i < v.size(); i++){
            temp = "";
            temp = v.at(i);
            trim(temp);
            vec.push_back(stoi(temp));
        }
        return vec;
    }

    /* Date Functions */
    bool leapYear(int year)
    {
        if (year % 4 == 0 && year % 100 != 0)
            return true;
        else if (year % 4 == 0 && year % 400 == 0)
            return true;
        return false;
    }

    unsigned int numDays(int year, int month)
    {
        unsigned int d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && leapYear(year))
            return 29;
        else
            return d[month - 1];
    }

    bool checkBetweenDates(Date &shorter, Date &mid, Date &higher)
    {
        return ((shorter <= mid) && (mid <= higher));
    }
}
