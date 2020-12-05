//
// Created by AdamOttvar on 2020-12-05
//

#include "day05.h"
#include <iterator>
#include <math.h>
#include <set>
#include <vector>

int day05(bool part_two) {
#ifndef AoC_RUN_TEST
    cout << "AoC day05: part " << (part_two ? "two" : "one") << endl;
#endif
    auto boardingPasses = AoC::read_file<string, vector<string>>("input/input05.txt");
    set<int> seatIDs;

    int result = 0;
    for (auto bp : boardingPasses) {
        int maxRow = 127;
        int minRow = 0;
        int maxCol = 7;
        int minCol = 0;
        for (auto c : bp) {
            if (c == 'F') {
                maxRow -= ceil((maxRow - minRow) / 2.0);
            } else if (c == 'B') {
                minRow += ceil((maxRow - minRow) / 2.0);
            } else if (c == 'L') {
                maxCol -= ceil((maxCol - minCol) / 2.0);
            } else if (c == 'R') {
                minCol += ceil((maxCol - minCol) / 2.0);
            } else {
                cerr << "Wrong char!!!" << endl;
            }
        }
        if (minRow != maxRow || minCol != maxCol) {
            cerr << "Error in calculation!" << endl;
            cout << "min: " << minRow << " max: " << maxRow << endl;
            cout << "min: " << minCol << " max: " << maxCol << endl;
            return result;
        }
        int row = maxRow;
        int col = maxCol;

        int seatID = row * 8 + col;
        seatIDs.insert(seatID);

        if (!part_two) {
            if (seatID > result)
                result = seatID;
        }
    }
    if (part_two) {
        result = 0;
        for (auto sId : seatIDs) {
            auto pos = seatIDs.find(sId + 1);
            if (pos == seatIDs.end()) {
                result = sId + 1;
                return result;
            }
        }
    }
    return result;
}

#ifndef AoC_RUN_TEST
int main() {
    int result;
    result = day05(true);
    cout << "Result: " << result << endl;
    return 0;
}
#endif