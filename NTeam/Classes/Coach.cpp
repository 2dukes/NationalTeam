

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

void Coach::addTrainedTeam(std::pair<std::string, Interval> toAdd)
{
    teamsTrained.push_back(toAdd);
}

bool Coach::operator<(const Coach &c) const
{
    if(cupsWon == c.cupsWon)
        return name < c.name;
    else
        return cupsWon < c.cupsWon;
}

void Coach::header()
{
    std::cout << std::endl;
    std::cout << std::left << std::setw(50) << "Name" <<  std::setw(10) << "Cups Won" << std::endl;
    std::cout << "===================================================================================================================================================================================================================" << endl;
}
