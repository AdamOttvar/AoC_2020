//
// Created by AdamOttvar on 2020-12-15
//

#include "day15.h"
#include <map>

int day15(bool part_two) {
#ifndef AoC_RUN_TEST
    cout << "AoC day15: part " << (part_two ? "two" : "one") << endl;
#endif
    map<int, int> numbers = {{0, 1}, {1, 2}, {5, 3}, {10, 4}, {3, 5}, {12, 6}};
    int lastNbrSpoken = 19;
    int newNbrSpoken;
    int targetIteration = (part_two ? 30000000 : 2020);
    for (int i = numbers.size() + 2; i <= targetIteration; i++) {
        if (numbers.count(lastNbrSpoken)) {
            newNbrSpoken = i - 1 - numbers[lastNbrSpoken];
            numbers[lastNbrSpoken] = i - 1;
        } else {
            numbers[lastNbrSpoken] = i - 1;
            newNbrSpoken = 0;
        }
        lastNbrSpoken = newNbrSpoken;
    }

    int result = newNbrSpoken;
    return result;
}

#ifndef AoC_RUN_TEST
int main() {
    int result;
    result = day15(false);
    cout << "Result: " << result << endl;
    result = day15(true);
    cout << "Result: " << result << endl;
    return 0;
}
#endif