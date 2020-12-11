//
// Created by AdamOttvar on 2020-12-11
//

#include "day11.h"
#include <algorithm>

static const std::vector<std::pair<int, int>> directions{{-1, -1},{-1, 0},{-1, 1},{1, -1},{1, 0},{1, 1},{0, 1},{0, -1}};

int findNeighbors1(vector<string> &seatings, int x_pos, int y_pos) {
    int neighbors = 0;
    for (auto dir : directions) {
        int x = x_pos + dir.first;
        int y = y_pos + dir.second;
        if (x >= 0 && x < seatings.size() && y >= 0 && y < seatings.front().length() &&
            seatings[x][y] == '#') {
            neighbors++;
        }
    }
    return neighbors;
}

int findNeighbors2(vector<string> &seatings, int x_pos, int y_pos) {
    int neighbors = 0;
    for (auto dir : directions) {
        int x = x_pos + dir.first;
        int y = y_pos + dir.second;

        while (x >= 0 && x < seatings.size() && y >= 0 && y < seatings.front().length()) {
            if (seatings[x][y] == '#') {
                neighbors++;
                break;
            } else if (seatings[x][y] == 'L') {
                break;
            }
            x += dir.first;
            y += dir.second;
        }
    }
    return neighbors;
}

    int day11(bool part_two) {
#ifndef AoC_RUN_TEST
    cout << "AoC day11: part " << (part_two ? "two" : "one") << endl;
#endif
    ifstream in("input/input11.txt");
    auto seatMap = AoC::read_file<string, vector<string>>("input/input11.txt");
    auto currentMap = seatMap;
    auto previousMap = seatMap;
    bool changed = true;
    int iterations = 0;
    int occupied = 0;

    int (*findFuncPtr)(vector<string> &, int, int) = part_two ? findNeighbors2 : findNeighbors1;

    while (changed) {
        iterations++;
        previousMap = currentMap;
        changed = false;
        for (int row = 0; row < seatMap.size(); row++) {
            for (int col = 0; col < seatMap[row].length(); col++) {
                if (previousMap[row][col] == 'L') {
                    int nbrofOccupied = findFuncPtr(previousMap, row, col);
                    if (nbrofOccupied == 0) {
                        currentMap[row][col] = '#';
                        changed = true;
                    }
                } else if (previousMap[row][col] == '#') {
                    int nbrofOccupied = findFuncPtr(previousMap, row, col);
                    int maxOccuToMove = part_two ? 5 : 4;
                    if (nbrofOccupied >= maxOccuToMove) {
                        currentMap[row][col] = 'L';
                        changed = true;
                    }
                }

            }
        }

        occupied = 0;
        for (int row = 0; row < currentMap.size(); row++) {
            for (int col = 0; col < currentMap[row].length(); col++) {
                occupied += currentMap[row][col] == '#';
            }
        }
    }
    cout << "Iterations: " << iterations << endl;
    cout << "Occupied: " << occupied << endl;
    cout << endl;

    return occupied;
}

#ifndef AoC_RUN_TEST
int main() {
    int result;
    result = day11(true);
    cout << "Result: " << result << endl;
    return 0;
}
#endif