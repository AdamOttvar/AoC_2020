//
// Created by AdamOttvar on 2020-12-06
//

#include "day06.h"
#include <algorithm>
#include <map>
#include <set>

int day06(bool part_two) {
#ifndef AoC_RUN_TEST
    cout << "AoC day06: part " << (part_two ? "two" : "one") << endl;
#endif
    ifstream inFile("input/input06.txt");

    int result = 0;

    if (inFile.is_open()) {
        std::string line;

        if (!part_two) {
            std::set<char> anyoneYes;
            while (std::getline(inFile, line)) {
                if (line.empty() || inFile.peek() == EOF) {
                    for (auto ch : line) {
                        anyoneYes.insert(ch);
                    }
                    result += anyoneYes.size();
                    anyoneYes.clear();
                } else {
                    for (auto ch : line) {
                        anyoneYes.insert(ch);
                    }
                }
            }
        } else {
            std::vector<std::set<char>> groupAnswers;
            while (std::getline(inFile, line)) {
                if (line.empty() || inFile.peek() == EOF) {

                    if (inFile.peek() == EOF) {
                        set<char> onePersonsAnswer;
                        for (auto ch : line) {
                            onePersonsAnswer.insert(ch);
                        }
                        groupAnswers.push_back(onePersonsAnswer);
                    }

                    if (groupAnswers.size() == 1) {
                        result += groupAnswers[0].size();
                    } else {
                        std::set<char> intsectTemp = groupAnswers[0];
                        for (auto person : groupAnswers) {
                            std::set<char> tempRes;
                            std::set_intersection(intsectTemp.begin(),
                                                  intsectTemp.end(),
                                                  person.begin(),
                                                  person.end(),
                                                  std::inserter(tempRes, tempRes.begin()));
                            intsectTemp = tempRes;
                        }

                        result += intsectTemp.size();
                    }
                    groupAnswers.clear();

                } else {
                    set<char> onePersonsAnswer;
                    for (auto ch : line) {
                        onePersonsAnswer.insert(ch);
                    }

                    groupAnswers.push_back(onePersonsAnswer);
                }
            }
        }

    } else {
        cout << "File not open" << endl;
    }

    return result;
}

#ifndef AoC_RUN_TEST
int main() {
    int result;
    result = day06(true);
    cout << "Result: " << result << endl;
    return 0;
}
#endif