//
// Created by AdamOttvar on 2020-11-25
//

#include "common.h"
#include <chrono>

using namespace std;

namespace AoC {
    double timeFunction(void (*pFunc)(bool), bool part2) {

        chrono::time_point<chrono::steady_clock> start, end;
        start = chrono::steady_clock::now();
        pFunc(part2);
        end = chrono::steady_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
        double t = elapsed_seconds.count(); // t number of seconds, represented as a `double`
        return t;
    }
} // namespace AoC