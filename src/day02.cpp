//
// Created by AdamOttvar on 2020-12-02
//

#include "common.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void day02(bool part_two = false) {
    cout << "AoC day02: part " << (part_two ? "two" : "one") << endl;
    std::ifstream infile("input/input02.txt");
    if (!infile) {
        cerr << "Couldn't read file" << endl;
        return;
    }
    int minOccur, maxOccur;
    string chara, passw;
    char character;
    int validPasswords = 0;
    std::string line;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        if (!(iss >> minOccur >> maxOccur >> chara >> passw)) {
            break;
        } // error
        maxOccur = abs(maxOccur);
        character = chara[0];

        if (!part_two) {
            int charCount = std::count_if(passw.begin(), passw.end(), [character](const char elem) { return elem == character; });

            if (charCount >= minOccur && charCount <= maxOccur) {
                validPasswords++;
            }

        } else {
            bool first = character == passw[minOccur - 1];
            bool second = character == passw[maxOccur - 1];

            if (first ^ second) {
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