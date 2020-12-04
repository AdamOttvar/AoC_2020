//
// Created by AdamOttvar on 2020-12-04
//

#include "day04.h"
#include "Passport.h"
#include <algorithm>
#include <map>

int day04(bool part_two) {
    cout << "AoC day04: part " << (part_two ? "two" : "one") << endl;
    ifstream inFile("input/input04.txt");
    int result = 0;
    vector<Passport> passports;
    if (inFile.is_open()) {
        std::map<std::string, std::string> inputData;
        std::string line;
        while (std::getline(inFile, line)) {
            if (line.empty()) {
                Passport newPass = Passport(inputData);
                passports.push_back(newPass);
                inputData.clear();
            } 
            else {
                std::stringstream ss(line);
                while (getline(ss, line, ' ')) {
                    std::stringstream ss2(line);
                    vector<std::string> valuePair;
                    while (getline(ss2, line, ':')) {
                        valuePair.push_back(line);
                    }
                    inputData.insert(pair<std::string, std::string>(valuePair[0], valuePair[1]));
                }
                if (inFile.peek() == EOF) {
                    Passport newPass = Passport(inputData);
                    passports.push_back(newPass);
                    inputData.clear();
                }
            }
        }

    } 
    else {
        cout << "File not open" << endl;
    }

    int validPassports = count_if(passports.begin(), passports.end(), [](Passport p) { return p.validatePassport(true); });
    return validPassports;
}

#ifndef AoC_RUN_TEST
int main() {
    int result;
    result = day04(false);
    cout << "Result: " << result << endl;
    return 0;
}
#endif