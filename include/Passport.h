//
// Passport.h
// Created by AdamOttvar on 2020-12-02
//

#ifndef _PASSPORT_H_
#define _PASSPORT_H_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

class Passport {
private:
    std::string byr;
    std::string iyr;
    std::string eyr;
    std::string hgt;
    std::string hcl;
    std::string ecl;
    std::string pid;
    std::string cid;
    std::string rawData;

public:
    inline Passport();
    inline Passport(std::string);
    inline Passport(std::map<std::string, std::string>);
    //inline Passport(int,int,int,std::string,std::string,std::string,unsigned long,int);

    inline bool validatePassport(bool cidValid);
    inline void print();

    //inline friend std::istream &operator>>(std::istream &input, Passport &P);
};

Passport::Passport() {
    byr = "";
    iyr = "";
    eyr = "";
    hgt = "";
    hcl = "";
    ecl = "";
    pid = "";
    cid = "";
    rawData = "";
}

Passport::Passport(std::string raw) {
    byr = "";
    iyr = "";
    eyr = "";
    hgt = "";
    hcl = "";
    ecl = "";
    pid = "";
    cid = "";
    rawData = raw;
}

Passport::Passport(std::map<std::string, std::string> inputData) {
    // for (std::pair<std::string,std::string> dat : inputData) {
    //     std::cout << dat.first << ": " << dat.second << std::endl;
    // }
    byr = inputData["byr"];
    iyr = inputData["iyr"];
    eyr = inputData["eyr"];
    hgt = inputData["hgt"];
    hcl = inputData["hcl"];
    ecl = inputData["ecl"];
    pid = inputData["pid"];
    cid = inputData["cid"];
}

/*
Passport::Passport(int byr, int iyr, int eyr, std::string hgt, std::string hcl, std::string ecl, unsigned long pid, int cid) {
    this->start = start;
    this->end = end;
    this->password = password;

    this->character = charact[0];
}
*/

bool Passport::validatePassport(bool cidValid) {
    bool passwordValidates = false;
    int missingFileds = 0;
    if (cidValid) {
        missingFileds += byr == "";
        missingFileds += iyr == "";
        missingFileds += eyr == "";
        missingFileds += hgt == "";
        missingFileds += hcl == "";
        missingFileds += ecl == "";
        missingFileds += pid == "";
    } else {
        missingFileds += byr == "";
        missingFileds += iyr == "";
        missingFileds += eyr == "";
        missingFileds += hgt == "";
        missingFileds += hcl == "";
        missingFileds += ecl == "";
        missingFileds += pid == "";
        missingFileds += cid == "";
    }

    passwordValidates = (missingFileds == 0) ? true : false;

    return passwordValidates;
}

void Passport::print() {
    std::cout << "byr:" << byr << " " << std::flush;
    std::cout << "iyr:" << iyr << " " << std::flush;
    std::cout << "eyr:" << eyr << " " << std::flush;
    std::cout << "hgt:" << hgt << " " << std::flush;
    std::cout << "hcl:" << hcl << " " << std::flush;
    std::cout << "ecl:" << ecl << " " << std::flush;
    std::cout << "pid:" << pid << " " << std::flush;
    std::cout << "cid:" << cid << " " << std::flush;
    std::cout << "rawData:" << rawData << " " << std::endl;
}

/*
std::istream &operator>>(std::istream &input, Passport &P) {
    std::string tempChar;
    input >> P.start >> P.end >> tempChar >> P.password;
    P.end = abs(P.end);
    P.character = tempChar[0];

    return input;
}
*/

#endif //_PASSWORD_H_