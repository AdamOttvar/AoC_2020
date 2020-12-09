//
// Created by AdamOttvar on 2020-12-08
//

#include "day08.h"
#include <sstream>
#include <vector>

void handleInput(string filename, vector<pair<string, int>> &instructions) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string operation;
            int param;
            ss >> operation >> param;
            instructions.push_back(make_pair(operation, param));
        }
    } else {
        cout << "File not open" << endl;
    }
}

bool runProgram(vector<pair<string, int>> &instructions, int &accumulator) {
    int nbrOfInstructions = instructions.size();
    bool indexVisited[nbrOfInstructions] = {false};

    int index = 0;
    while (index < nbrOfInstructions) {
        if (indexVisited[index]) {
            return false;
        }
        indexVisited[index] = true;

        string operation = instructions[index].first;
        int arg = instructions[index].second;

        if (operation == "nop") {
            index++;
        } else if (operation == "jmp") {
            index += arg;
        } else if (operation == "acc") {
            accumulator += arg;
            index++;
        } else {
            cerr << "Invalid operation! " << operation << endl;
        }
    }

    return true;
}

int day08(bool part_two) {
#ifndef AoC_RUN_TEST
    cout << "AoC day08: part " << (part_two ? "two" : "one") << endl;
#endif
    vector<pair<string, int>> instructions;
    handleInput("input/input08.txt", instructions);

    int result = 0;
    if (!part_two) {
        bool success = runProgram(instructions, result);
        return result;
    } else {
        for (int i = 0; i < instructions.size(); i++) {
            result = 0;
            vector<pair<string, int>> alteredInstructions = instructions;
            if (instructions[i].first == "nop") {
                alteredInstructions[i] = make_pair("jmp", instructions[i].second);
            } else if (instructions[i].first == "jmp") {
                alteredInstructions[i] = make_pair("nop", instructions[i].second);
            }
            if (runProgram(alteredInstructions, result)) {
                return result;
            }
        }
    }
    return 0;
}

#ifndef AoC_RUN_TEST
int main() {
    int result;
    result = day08(false);
    cout << "Result: " << result << endl;
    result = day08(true);
    cout << "Result: " << result << endl;
    return 0;
}
#endif