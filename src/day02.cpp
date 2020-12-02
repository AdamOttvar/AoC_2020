//
// Created by AdamOttvar on 2020-12-02
//

#include "day02.h"
#include "Password.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int day02(bool part_two) {
    cout << "AoC day02: part " << (part_two ? "two" : "one") << endl;
    auto passwords = AoC::read_file<Password, vector<Password>>("input/input02.txt");
    int validPasswords = 0;

    for (auto pass : passwords) {
        if (!part_two) {

            if (pass.validatePassword(false)) {
                validPasswords++;
            }

        } else {
            if (pass.validatePassword(true)) {
                validPasswords++;
            }
        }
    }

    return validPasswords;
}

#ifndef AoC_RUN_TEST
int main() {
    int result;
    result = day02(false);
    cout << "Result: " << result << endl;
    result = day02(true);
    cout << "Result: " << result << endl;
    return 0;
}
#endif