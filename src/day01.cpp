//
// Created by AdamOttvar on 2020-12-01
//

#include "common.h"
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

void day01(bool part_two) {
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

    cout << "Result: " << result << endl;
}

int main() {
    day01(false);
    day01(true);
    return 0;
}