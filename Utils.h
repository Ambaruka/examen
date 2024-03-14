//
// Created by AmbarPC on 13/03/2024.
//

#ifndef INTENTO_UTILS_H
#define INTENTO_UTILS_H

#include <cstdlib>

namespace combat_utils {
    int getRolledAttack(int attack) {
        srand(time(NULL));
        int lowerLimit = attack * .80;
        return (rand() % (attack - lowerLimit)) + lowerLimit;
    }
}

#endif //INTENTO_UTILS_H
