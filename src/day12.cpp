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
    int direction = 1; // 0=north, 1=east, 2=south, 3=west

    for (auto instruction : instructions) {
        char action = instruction[0];
        int value = atoi(instruction.substr(1).c_str());
        //cout << "Action: " << action << " Value: " << value << endl;
        switch (action) {
        case 'N': 
            yPos += value;
            break;
        case 'S': 
            yPos -= value;
            break;
        case 'E': 
            xPos += value;
            break;
        case 'W': 
            xPos -= value;
            break;
        case 'R':
            switch (value)
            {
            case 90:
                direction++;
                if (direction == 4)
                    direction = 0;
                break;
            case 180:
                direction += 2;
                if (direction == 4)
                    direction = 0;
                else if (direction == 5)
                    direction = 1;
                break;
            case 270:
                direction += 3;
                if (direction == 4)
                    direction = 0;
                else if (direction == 5)
                    direction = 1;
                else if (direction == 6)
                    direction = 2;
                break;
            default:
                break;
            }
            break;
        case 'L':
            switch (value) {
            case 90:
                direction--;
                if (direction == -1)
                    direction = 3;
                break;
            case 180:
                direction -= 2;
                if (direction == -1)
                    direction = 3;
                else if (direction == -2)
                    direction = 2;
                break;
            case 270:
                direction -= 3;
                if (direction == -1)
                    direction = 3;
                else if (direction == -2)
                    direction = 2;
                else if (direction == -3)
                    direction = 1;
                break;
            default:
                break;
            }
            break;
        case 'F': 
            switch (direction)
            {
            case 0:
                yPos += value;
                break;
            case 1:
                xPos += value;
                break;
            case 2:
                yPos -= value;
                break;
            case 3:
                xPos -= value;
                break;
            default:
                cerr << "Faulty direction!" << endl;
                break;
            }
            break;
        default:
            cerr << "Faulty action!" << endl;
        }

        //cout << "X: " << xPos << " Y: " << yPos << " Dir: " << direction << endl;
    }

    return abs(xPos) + abs(yPos);
}

#ifndef AoC_RUN_TEST
int main() {
    int result;
    result = day12(false);
    cout << "Result: " << result << endl;
    return 0;
}
#endif