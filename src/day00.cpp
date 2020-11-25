//
// Created by AdamOttvar on 2020-11-25
//

#include "day00.h"

void day00(bool part_two) {
    cout << "AoC day00: part " << (part_two ? "two" : "one") << endl;
    ifstream in("input/input00.txt");
    if (in.is_open()) {
        int mass;
        long int total = 0;
        while (in >> mass) {
            total += mass / 3 - 2;
        }
        cout << "Fuel needed: " << total << endl;

    } else {
        cout << "File not open" << endl;
    }
}

int main() {
    day00(false);
    return 0;
}