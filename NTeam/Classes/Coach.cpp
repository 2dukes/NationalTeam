
#include "Coach.h"
#include "../NecessaryFunctions_NameSpaces.h"
#include <iomanip>

Interval::Interval(Date begin, Date end)
{
    beginD = begin;
    endD = end;
}

Date Interval::getBeginDate() const
{
    return beginD;
}

Date Interval::getEndDate() const
{
    return endD;
}

void Interval::setBeginDate(Date begin)
{
    beginD = begin;
}
void Interval::setEndDate(Date end)
{
    endD = end;
}

/*
Pretende-se manter informação sobre todos os selecionadores da seleção nacional de futebol. O
selecionador é caracterizado por nome, número de títulos ganhos e seleções que já selecionou (local, data).
Use uma árvore binária de pesquisa para guardar essa informação, que deve estar ordenada por número
de títulos ganhos, e, em caso de empate, por nome de selecionador. Sempre que um selecionador é
convocado para orientar a seleção nacional, deve ser atualizada a informação presente na árvore. Devem
ser permitidas listagens várias, tirando partido da ordenação da árvore.
 */

Coach::Coach(string name, unsigned int cupsWon, std::list<std::pair<std::string, Interval>> teamsTrained)
{
    this->name = name;
    this->cupsWon = cupsWon;
    this->teamsTrained = teamsTrained;
}

std::string Coach::getName() const
{
    return name;
}

unsigned int Coach::getCupsWon() const
{
    return cupsWon;
}
std::list<std::pair<std::string, Interval>> Coach::getTeamsTrained() const
{
    return teamsTrained;
}

void Coach::setName(std::string name)
{
    this->name = name;
}

void Coach::setCupsWon(unsigned int cupsWon)
{
    this->cupsWon = cupsWon;
}

bool Coach::addTrainedTeam(std::pair<std::string, Interval> toAdd)
{
    for(auto &x: teamsTrained)
    {
        if(generalFunctions::checkBetweenDates(x.second.getBeginDate(), toAdd.second.getBeginDate(), x.second.getEndDate())
           || generalFunctions::checkBetweenDates(x.second.getBeginDate(), toAdd.second.getEndDate(), x.second.getEndDate())
           || generalFunctions::checkBetweenDates(toAdd.second.getBeginDate(), x.second.getBeginDate(), toAdd.second.getEndDate())
           || generalFunctions::checkBetweenDates(toAdd.second.getBeginDate(), x.second.getEndDate(), toAdd.second.getEndDate()))
        {
            cout << "Team not Added because of date convergence (" << x.second.getBeginDate().getDate() << " - " << x.second.getEndDate().getDate() << endl << endl;
            return false;
        }
    }
    teamsTrained.push_back(toAdd);
    cout << "Team successfully added!" << endl << endl;
    return true;
}

bool Coach::removeTrainedTeam(std::pair<std::string, Interval> toRemove){
    for(std::list<std::pair<std::string, Interval>>::iterator iTr = teamsTrained.begin(); iTr != teamsTrained.end(); iTr++)
    {
        if(iTr->second.getBeginDate() == toRemove.second.getBeginDate() && iTr->second.getEndDate() == toRemove.second.getEndDate() && iTr->first == toRemove.first)
        {
            teamsTrained.erase(iTr);
            cout << "Team Trained Successfully removed!" << endl << endl;
            return true;
        }
    }
    cout << "Team Trained not Inserted!" << endl << endl;

    return false;
}

bool Coach::operator<(const Coach &c) const
{
    if(cupsWon == c.cupsWon)
        return name < c.name;
    else
        return cupsWon > c.cupsWon;
}

void Coach::header()
{
    std::cout << std::endl;
    std::cout << std::left << std::setw(50) << "Name" <<  std::setw(10) << "Cups Won" << std::endl;
    std::cout << "===================================================================================================================================================================================================================" << endl;
}
