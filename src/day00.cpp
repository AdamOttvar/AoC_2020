//
// Created by AdamOttvar on 2020-11-25
//

#include "common.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace AoC;

long int calculateFuel(int mass) {
    long int fuelNeeded = 0;
    long int fuelForMass = mass / 3 - 2;
    while (fuelForMass > 0) {
        fuelNeeded += fuelForMass;
        fuelForMass = fuelForMass / 3 - 2;
    }
    return fuelNeeded;
}

void day00(bool part_two) {
    cout << "AoC day00: part " << (part_two ? "two" : "one") << endl;
    ifstream in("input/input00.txt");
    if (in.is_open()) {
        int mass;
        long int total = 0;
        while (in >> mass) {
            if (!part_two) {
                total += mass / 3 - 2;
            } else {
                total += calculateFuel(mass);
            }
        }
        cout << "Fuel needed: " << total << endl;

    } else {
        cout << "File not open" << endl;
    }
}

#ifndef AoC_RUN_TEST
int main() {
    //day00();
    //day00(true);

    double elapsedTime = timeFunction(day00, false);
    cout << "Part 1 took: " << elapsedTime << " s" << endl;
    elapsedTime = timeFunction(day00, true);
    cout << "Part 2 took: " << elapsedTime << " s" << endl;

    return 0;
}
#endif