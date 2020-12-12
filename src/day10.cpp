//
// Created by AdamOttvar on 2020-12-11
//

#include "day10.h"
#include <algorithm>
#include <numeric>

long long day10(bool part_two) {
#ifndef AoC_RUN_TEST
    cout << "AoC day10: part " << (part_two ? "two" : "one") << endl;
#endif
    auto adapters = AoC::read_file<int, vector<int>>("input/input10.txt");
    adapters.push_back(0);
    auto it = max_element(begin(adapters), end(adapters));
    adapters.push_back(*it + 3);

    if (!part_two) {
        int currentAdapter = 0;
        int ones = 0;
        int threes = 0;

        sort(adapters.begin(), adapters.end(), greater<int>());
        while (adapters.size() > 0) {
            int difference = adapters.back() - currentAdapter;
            if (difference == 1) {
                ones++;
            }
            else if (difference == 3) {
                threes++;
            }
            currentAdapter = adapters.back();
            adapters.pop_back();
        }
        return ones*threes;
    }
    else {
        sort(adapters.begin(), adapters.end());
        vector<int> diffs(adapters.size());
        adjacent_difference(adapters.begin(), adapters.end(), diffs.begin());
        vector<int> sequences;
        int counter = 0;
        for (int i = 0; i < diffs.size(); i++) {
            if (diffs[i] == 3) {
                sequences.push_back(counter);
                counter = 1;
            }
            else {
                counter++;
            }
        }

        long long result = 1;
        for (auto ct : sequences) {
            if (ct == 3)
                result = result * 2;
            else if (ct == 4)
                result = result * 4;
            else if (ct == 5)
                result = result * 7;

        }
        return result;
    }
}

#ifndef AoC_RUN_TEST
int main() {
    long long result;
    result = day10(false);
    cout << "Result: " << result << endl;
    result = day10(true);
    cout << "Result: " << result << endl;
    return 0;
}
#endif