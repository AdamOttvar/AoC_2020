//
// Created by AdamOttvar on 2020-12-01
//

#include "day01.h"
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int day01(bool part_two) {
    cout << "AoC day01: part " << (part_two ? "two" : "one") << endl;
    auto entries = AoC::read_file<int, vector<int>>("input/input01.txt");
    int result;

    if (!part_two) {
        for (auto entry : entries) {
            auto it = find_if(entries.begin(), entries.end(), [=](const int elem) { return entry + elem == 2020; });
            if (it != entries.end()) {
                result = *it * entry;
                break;
            }
        }
    }
    else {
        for (auto vi = entries.begin(); vi != entries.end(); vi++)
            for (auto vj = next(vi, 1); vj != entries.end(); vj++)
                for (auto vk = next(vj, 1); vk != entries.end(); vk++)
                    if (*vi + *vj + *vk == 2020)
                        result = *vi * *vj * *vk;
    }

    return result;
}

#ifndef AoC_RUN_TEST
int main() {
    int result;
    result = day01(false);
    cout << "Result: " << result << endl;
    result = day01(true);
    cout << "Result: " << result << endl;
    return 0;
}
#endif