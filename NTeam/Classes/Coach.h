#ifndef NTEAM_COACH_H
#define NTEAM_COACH_H

#include <string>
#include <list>
#include "Date.h"
#include "bst.h"
/*
Pretende-se manter informação sobre todos os selecionadores da seleção nacional de futebol. O
selecionador é caracterizado por nome, número de títulos ganhos e seleções que já selecionou (local, data).
Use uma árvore binária de pesquisa para guardar essa informação, que deve estar ordenada por número
de títulos ganhos, e, em caso de empate, por nome de selecionador. Sempre que um selecionador é
convocado para orientar a seleção nacional, deve ser atualizada a informação presente na árvore. Devem
ser permitidas listagens várias, tirando partido da ordenação da árvore.
 */

class Interval {
public:
    Interval(Date begin, Date end);
    Date getBeginDate() const;
    Date getEndDate() const;

    void setBeginDate(Date begin);
    void setEndDate(Date end);
private:
    Date beginD;
    Date endD;
};

class Coach {
public:
    Coach(string name, unsigned int cupsWon, std::list<std::pair<std::string, Interval>> teamsTrained);
    bool operator<(const Coach &c) const;

    std::string getName() const;
    unsigned int getCupsWon() const;
    std::list<std::pair<std::string, Interval>> getTeamsTrained() const;

    void setName(std::string name);
    void setCupsWon(unsigned int cupsWon);
    bool addTrainedTeam(std::pair<std::string, Interval> toAdd);
    bool removeTrainedTeam(std::pair<std::string, Interval> toRemove);

    static void header();


private:
    std::string name;
    unsigned int cupsWon;
    std::list<std::pair<std::string, Interval>> teamsTrained;
};


#endif //NTEAM_COACH_H
