//
// Created by AdamOttvar on 2020-12-05
//

#include "day05.h"
#include <algorithm>
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
        string rowString = bp.substr(0, 7);
        string colString = bp.substr(7, 3);
        replace(rowString.begin(), rowString.end(), 'F', '0');
        replace(rowString.begin(), rowString.end(), 'B', '1');
        replace(colString.begin(), colString.end(), 'L', '0');
        replace(colString.begin(), colString.end(), 'R', '1');
        int row = stoi(rowString, nullptr, 2);
        int col = stoi(colString, nullptr, 2);
        int seatID = row * 8 + col;
        seatIDs.insert(seatID);
    }

    if (!part_two) {
        result = *seatIDs.rbegin();
    } else {
        result = *adjacent_find(seatIDs.begin(), seatIDs.end(), [](int a, int b) { return (a + 1) != b; }) + 1;
    }
    return result;
}

#ifndef AoC_RUN_TEST
int main() {
    int result;
    result = day05(false);
    cout << "Result: " << result << endl;
    result = day05(true);
    cout << "Result: " << result << endl;
    return 0;
}
#endif