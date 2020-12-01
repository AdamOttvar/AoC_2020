//
// Created by AdamOttvar on 2020-11-25
//

#ifndef _COMMON_H_
#define _COMMON_H_

#include <chrono>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

namespace AoC {
    // Function for timing functions
    double timeFunction(void (*pFunc)(bool), bool part2) {
        chrono::time_point<chrono::steady_clock> start, end;
        start = chrono::steady_clock::now();
        pFunc(part2);
        end = chrono::steady_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
        double t = elapsed_seconds.count(); // t number of seconds, represented as a `double`
        return t;
    }

    // Read file into whatever container you like
    template <typename T_value = char,
              typename T_container = std::vector<T_value>>
    auto read_file(const std::string filename) {
        T_container buffer;

        std::ifstream file(filename);

        if (!file) {
            cerr << "Could not open file!" << endl;
        }
        else {
            std::copy(
                std::istream_iterator<T_value>(file),
                std::istream_iterator<T_value>(),
                std::back_inserter(buffer));
        }

        return buffer;
    }

} // namespace AoC

#endif //_COMMON_H_
