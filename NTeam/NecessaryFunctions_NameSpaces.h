//
// Created by Rui Pinto on 10/29/2019.
//

#ifndef NTEAM_NECESSARYFUNCTIONS_NAMESPACES_H
#define NTEAM_NECESSARYFUNCTIONS_NAMESPACES_H

#include <string>
#include "Classes/Staff.h"

namespace verifyInputs {
    bool verifyString(std::string auxStr);
    bool verifyDate(std::string auxStr);
    bool verifyNumber();
}

namespace getWorkers {
    Staff * WorkerLookUp();
}

#endif //NTEAM_NECESSARYFUNCTIONS_NAMESPACES_H
