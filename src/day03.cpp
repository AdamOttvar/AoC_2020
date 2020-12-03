//
// Created by AdamOttvar on 2020-12-03
//

#include "day03.h"
#include <numeric>

unsigned long day03(bool part_two) {
    cout << "AoC day03: part " << (part_two ? "two" : "one") << endl;
    auto slopeMap = AoC::read_file<string, vector<string>>("input/input03.txt");
    vector<pair<int, int>> slopes{{1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};

    vector<int> nbrOfTreesInSlopes;
    int slopeWidth = slopeMap[0].length();
    for (auto slope : slopes) {
        int col = 0;
        int nbrOfTrees = 0;
        for (int row = 0; row < slopeMap.size(); row += slope.second) {
            nbrOfTrees += (slopeMap[row][col] == '#') ? 1 : 0;
            col += slope.first;
            col = (col >= slopeWidth) ? col - slopeWidth : col;
        }
        nbrOfTreesInSlopes.push_back(nbrOfTrees);
    }

    unsigned long nbrOfTreesMulti = std::accumulate(begin(nbrOfTreesInSlopes), end(nbrOfTreesInSlopes), 1, std::multiplies<>());
    return (part_two ? nbrOfTreesMulti : nbrOfTreesInSlopes[1]);
}

#ifndef AoC_RUN_TEST
int main() {
    unsigned long result;
    result = day03(false);
    cout << "Result: " << result << endl;
    result = day03(true);
    cout << "Result: " << result << endl;
    return 0;
}
#endif