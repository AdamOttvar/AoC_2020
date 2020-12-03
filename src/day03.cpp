//
// Created by AdamOttvar on 2020-12-03
//

#include "day03.h"

unsigned long day03(bool part_two) {
    cout << "AoC day03: part " << (part_two ? "two" : "one") << endl;
    auto slopeMap = AoC::read_file<string, vector<string>>("input/input03.txt");

    vector<vector<int>> slopes;
    if (!part_two) {
        slopes = {{3, 1}};
    } else {
        slopes = {{1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};
    }

    vector<int> nbrOfTreesInSlopes;
    for (auto slope : slopes) {
        int col = 0;
        int nbrOfTrees = 0;
        for (int row = 0; row < slopeMap.size(); row += slope[1]) {

            if (slopeMap[row][col] == '#') {
                //slopeMap[row][col] = 'X';
                nbrOfTrees++;
            } else {
                //slopeMap[row][col] = 'O';
            }

            col += slope[0];
            if (col > slopeMap[row].length() - 1) {
                col = col - slopeMap[row].length();
            }
        }
        nbrOfTreesInSlopes.push_back(nbrOfTrees);
    }

    unsigned long nbrOfTreesMulti = 1;
    for (auto trees : nbrOfTreesInSlopes) {
        nbrOfTreesMulti *= trees;
    }
    return nbrOfTreesMulti;
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