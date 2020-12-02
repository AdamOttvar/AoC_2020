//
// Created by AdamOttvar on 2020-12-02
//

#include "common.h"
#include "Password.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void day02(bool part_two = false) {
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
    cout << "Result: " << validPasswords << endl;
}

int main() {
    day02(false);
    day02(true);
    return 0;
}