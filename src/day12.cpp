//
// Created by AdamOttvar on 2020-12-12
//

#include "day12.h"
#include <math.h>

int day12(bool part_two) {
#ifndef AoC_RUN_TEST
    cout << "AoC day12: part " << (part_two ? "two" : "one") << endl;
#endif
    auto instructions = AoC::read_file<string, vector<string>>("input/input12.txt");
    int xPos = 0;
    int yPos = 0;
    int xWayp = 10;
    int yWayp = 1;
    int direction = 1; // 0=north, 1=east, 2=south, 3=west

    for (auto instruction : instructions) {
        char action = instruction[0];
        int value = atoi(instruction.substr(1).c_str());
        int oldX = xWayp;
        int oldY = yWayp;

        switch (action) {
        case 'N':
            yWayp += value;
            break;
        case 'S':
            yWayp -= value;
            break;
        case 'E':
            xWayp += value;
            break;
        case 'W':
            xWayp -= value;
            break;
        case 'R':
            switch (value)
            {
            case 90:
                xWayp = oldY;
                yWayp = -oldX;
                break;
            case 180:
                xWayp = -oldX;
                yWayp = -oldY;
                break;
            case 270:
                xWayp = -oldY;
                yWayp = oldX;
                break;
            default:
                break;
            }
            break;
        case 'L':
            switch (value) {
            case 90:
                xWayp = -oldY;
                yWayp = oldX;
                break;
            case 180:
                xWayp = -oldX;
                yWayp = -oldY;
                break;
            case 270:
                xWayp = oldY;
                yWayp = -oldX;
                break;
            default:
                break;
            }
            break;
        case 'F':
            xPos += value * xWayp;
            yPos += value * yWayp;
            break;
        default:
            cerr << "Faulty action!" << endl;
        }
    }

    return abs(xPos) + abs(yPos);
}

#ifndef AoC_RUN_TEST
int main() {
    int result;
    result = day12(true);
    cout << "Result: " << result << endl;
    return 0;
}
#endif