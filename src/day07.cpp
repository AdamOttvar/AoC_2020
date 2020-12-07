//
// Created by AdamOttvar on 2020-12-07
//

#include "day07.h"
#include <map>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

void readLuggageRules(string textfile, map<string, set<string>> &containedIn, map<string, vector<tuple<int, string>>> &contains) {
    ifstream inFile(textfile);
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            vector<string> splittedLine;
            string linePart;

            while (getline(ss, linePart, ' ')) {
                splittedLine.push_back(linePart);
            }

            string parent = splittedLine[0] + " " + splittedLine[1];

            // Contains no bags
            if (splittedLine[4] == "no") {
                continue;

            }
            // Contains mulitple colored bags
            else if (splittedLine.size() > 8) {
                for (size_t i = 4; i < splittedLine.size(); i += 4) {
                    int nbrOfBags = atoi(splittedLine[i].c_str());
                    if (nbrOfBags != 0) {
                        string child = splittedLine[i + 1] + " " + splittedLine[i + 2];
                        containedIn[child].insert(parent);
                        contains[parent].push_back(make_tuple(nbrOfBags, child));
                    }
                }
            }
            // Contains one colored bags
            else {
                int nbrOfBags = atoi(splittedLine[4].c_str());
                string child = splittedLine[5] + " " + splittedLine[6];
                containedIn[child].insert(parent);
                contains[parent].push_back(make_tuple(nbrOfBags, child));
            }
        }
    } else {
        cout << "File not open" << endl;
    }
}

void checkColorParents(string color, map<string, set<string>> &luggageMap, set<string> &goldHolders) {
    for (auto lu : luggageMap[color]) {
        goldHolders.insert(lu);
        checkColorParents(lu, luggageMap, goldHolders);
    }
}

long checkColorChildren(string color, map<string, vector<tuple<int, string>>> &luggageMap) {
    long nbrOfBags = 0;
    for (auto tu : luggageMap[color]) {
        nbrOfBags += get<0>(tu);
        nbrOfBags += get<0>(tu) * checkColorChildren(get<1>(tu), luggageMap);
    }

    return nbrOfBags;
}

int day07(bool part_two) {
    cout << "AoC day07: part " << (part_two ? "two" : "one") << endl;
    string input = "input/input07.txt";

    map<string, set<string>> containedIn;
    map<string, vector<tuple<int, string>>> contains;

    readLuggageRules(input, containedIn, contains);

    int result = 0;
    if (!part_two) {
        set<string> canHoldGold{};
        checkColorParents("shiny gold", containedIn, canHoldGold);
        result = canHoldGold.size();
    }
    else {
        result = checkColorChildren("shiny gold", contains);
    }

    return result;
}

#ifndef AoC_RUN_TEST
int main() {
    int result;
    result = day07(false);
    cout << "Result: " << result << endl;
    result = day07(true);
    cout << "Result: " << result << endl;
    return 0;
}
#endif