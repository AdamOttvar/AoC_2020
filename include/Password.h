//
// Password.h
// Created by AdamOttvar on 2020-12-02
//

#ifndef _PASSWORD_H_
#define _PASSWORD_H_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Password {
private:
    int start;
    int end;
    char character;
    std::string password;

public:
    Password() : start(1), end(2), character('a'), password("password"){};
    Password(int start, int end, char character, std::string password) : start(start), end(end), character(character), password(password){};
    Password(int, int, std::string, std::string);

    // OTCP = Official Toboggan Corporate Policy
    bool validatePassword(bool OTCP);
    void print();

    friend std::istream &operator>>(std::istream &input, Password &P);
};

Password::Password(int start, int end, std::string charact, std::string password) {
    this->start = start;
    this->end = end;
    this->password = password;

    this->character = charact[0];
}

bool Password::validatePassword(bool OTCP) {
    // OTCP = Official Toboggan Corporate Policy
    bool passwordValidates = false;
    if (OTCP) {
        bool first = character == password[start - 1];
        bool second = character == password[end - 1];

        if (first ^ second) {
            passwordValidates = true;
        }

    } else { // "Wrong" password policy

        int charCount = std::count_if(password.begin(), password.end(), [=](const char elem) { return elem == character; });

        if (charCount >= start && charCount <= end) {
            passwordValidates = true;
        }
    }

    return passwordValidates;
}

void Password::print() {
    std::cout << "Password: " << this->password << std::endl;
}

std::istream &operator>>(std::istream &input, Password &P) {
    std::string tempChar;
    input >> P.start >> P.end >> tempChar >> P.password;
    P.end = abs(P.end);
    P.character = tempChar[0];

    return input;
}

#endif //_PASSWORD_H_