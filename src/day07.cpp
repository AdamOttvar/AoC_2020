//
// Created by AdamOttvar on 2020-12-07
//

#include "day07.h"
#include <map>
#include <set>

std::map<std::string, std::set<std::string>> readLuggageRules(std::string textfile) {
    ifstream inFile(textfile);
    map<string, set<string>> containedIn;
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::string delimiter = " bags contain ";
            std::string parent = line.substr(0, line.find(delimiter));
            std::string children = line.substr(line.find(delimiter) + delimiter.length());
            int pos = children.find(',', 0);
            if (children == "no other bags.") {
                // No bags
            } else if (pos == string::npos) {
                int bagPos = children.find("bag");
                string child = children.substr(2, bagPos - 3);
                map<string, set<string>>::iterator it = containedIn.find(child);
                if (it != containedIn.end()) {
                    //element found;
                    containedIn[child].insert(parent);
                } else {
                    containedIn[child] = {parent};
                }
            } else {
                vector<int> positions;
                while (pos != string::npos) {
                    positions.push_back(pos);
                    pos = children.find(',', pos + 1);
                }
                int start = 0;
                for (int i : positions) {
                    string oneColor = children.substr(start, i - start);
                    int bagPos = oneColor.find("bag");
                    string child = oneColor.substr(2, bagPos - 3);
                    map<string, set<string>>::iterator it = containedIn.find(child);
                    if (it != containedIn.end()) {
                        //element found;
                        containedIn[child].insert(parent);
                    } else {
                        containedIn[child] = {parent};
                    }
                    start = i + 2;
                }
                string oneColor = children.substr(start);
                int bagPos = oneColor.find("bag");
                string child = oneColor.substr(2, bagPos - 3);
                map<string, set<string>>::iterator it = containedIn.find(child);
                if (it != containedIn.end()) {
                    //element found;
                    containedIn[child].insert(parent);
                } else {
                    containedIn[child] = {parent};
                }
            }
        }
    } else {
        cout << "File not open" << endl;
    }

    return containedIn;
}

void checkColorParents(std::string color, std::map<std::string, std::set<std::string>> &luggageMap, std::set<string> &goldHolders) {
    for (auto lu : luggageMap[color]) {
        goldHolders.insert(lu);
        checkColorParents(lu, luggageMap, goldHolders);
    }
}

int day07(bool part_two) {
    cout << "AoC day07: part " << (part_two ? "two" : "one") << endl;
    string input = "input/input07.txt";
    int result = 0;
    map<string, set<string>> containedIn = readLuggageRules(input);

    std::set<std::string> canHoldGold{};

    // for (auto s : containedIn) {
    //     cout << "." << s.first << "." << endl;
    //     for (auto t : s.second) {
    //         cout << "  ." << t << "." << endl;
    //     }
    // }

    checkColorParents("shiny gold", containedIn, canHoldGold);

    result = canHoldGold.size();

    return result;
}

#ifndef AoC_RUN_TEST
int main() {
    int result;
    result = day07(false);
    cout << "Result: " << result << endl;
    return 0;
}
#endif