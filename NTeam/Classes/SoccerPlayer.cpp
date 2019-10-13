//
// Created by Rui Pinto on 10/11/2019.
//

#include "SoccerPlayer.h"

int SoccerPlayer::getSalary() const {
    return salary;
}

int SoccerPlayer::getEnsuranceValue() const {
    if (injured)
        return 0.05 * salary * daysActive * 3;
    return 0.05 * salary * daysActive;
}
