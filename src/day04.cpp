//
// Created by AdamOttvar on 2020-12-04
//

#include "day04.h"
#include "Passport.h"
#include <algorithm>
#include <map>

int day04(bool part_two) {
#ifndef AoC_RUN_TEST
    cout << "AoC day04: part " << (part_two ? "two" : "one") << endl;
#endif
    ifstream inFile("input/input04.txt");
    int result = 0;
    vector<Passport> passports;

    if (inFile.is_open()) {
        std::map<std::string, std::string> inputData;
        std::string line;
        std::string inputLine;

        while (std::getline(inFile, line)) {
            if (line.empty() || inFile.peek() == EOF) {
                inputLine.append(" ");
                inputLine.append(line);
                Passport newPass = Passport(inputLine);
                passports.push_back(newPass);
                inputLine.clear();
            } else {
                inputLine.append(" ");
                inputLine.append(line);
            }
        }

    } else {
        cout << "File not open" << endl;
    }

    int validPassports;
    if (!part_two)
        validPassports = count_if(passports.begin(), passports.end(), [](Passport p) { return p.validatePassportBasic(true); });
    else
        validPassports = count_if(passports.begin(), passports.end(), [](Passport p) { return p.validatePassport(true); });

    return validPassports;
}

#ifndef AoC_RUN_TEST
int main() {
    int result;
    result = day04(false);
    cout << "Result: " << result << endl;
    result = day04(true);
    cout << "Result: " << result << endl;
    return 0;
}
#endif