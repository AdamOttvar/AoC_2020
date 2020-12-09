//
// Created by AdamOttvar on 2020-12-09
//

#include "day09.h"
#include <algorithm>
#include <math.h>

int day09(bool part_two) {
    cout << "AoC day09: part " << (part_two ? "two" : "one") << endl;
    int result = 0;
    auto numbers = AoC::read_file<int, vector<int>>("input/input09.txt");

    int preambleLength = 25;

    for (int i = preambleLength; i < numbers.size(); i++) {
        vector<int> preambleVector(&numbers[i - preambleLength], &numbers[i]);
        int currentNumber = numbers[i];
        vector<int>::iterator it;
        bool found = false;
        for (auto preambleNumber : preambleVector) {
            if (preambleNumber == abs(currentNumber - preambleNumber)) {
                continue;
            }
            it = find(preambleVector.begin(), preambleVector.end(), abs(preambleNumber - currentNumber));
            if (it != preambleVector.end()) {
                found = true;
                break;
            }
        }
        if (!found) {
            result = currentNumber;
            break;
        }
    }

    if (part_two) {
        for (int i = 0; i < numbers.size(); i++) {
            int j = i;
            long sum = 0;
            while (sum < result) {
                sum += numbers[j];
                if (sum == result) {
                    int min = *min_element(&numbers[i], &numbers[j]);
                    int max = *max_element(&numbers[i], &numbers[j]);
                    return min + max;
                }
                j++;
            }
        }
    }

    return result;
}

#ifndef AoC_RUN_TEST
int main() {
    int result;
    result = day09(false);
    cout << "Result: " << result << endl;
    result = day09(true);
    cout << "Result: " << result << endl;
    return 0;
}
#endif