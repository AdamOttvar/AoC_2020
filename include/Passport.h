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
#include <set>

class Passport {
private:
    int byr;
    int iyr;
    int eyr;
    std::string hgt;
    std::string hcl;
    std::string ecl;
    std::string pid;
    int cid;
    std::string rawData;

    inline std::map<std::string, std::string> handleInput(std::string raw);

    inline bool validateHeight();
    inline bool validateHairColor();
    inline bool validateEyeColor();
    inline bool validatePassportID();
    inline bool validateCountryID();

public:
    inline Passport();
    inline Passport(std::string raw) : Passport(handleInput(raw)) {};
    inline Passport(std::map<std::string, std::string>);
    //inline Passport(int,int,int,std::string,std::string,std::string,unsigned long,int);

    inline bool validatePassportBasic(bool cidValid);
    inline bool validatePassport(bool cidValid);
    inline void print();

    //inline friend std::istream &operator>>(std::istream &input, Passport &P);
};

Passport::Passport() {
    byr = 0;
    iyr = 0;
    eyr = 0;
    hgt = "";
    hcl = "";
    ecl = "";
    pid = "";
    cid = 0;
}

Passport::Passport(std::map<std::string, std::string> inputData) {
    // for (std::pair<std::string,std::string> dat : inputData) {
    //     std::cout << dat.first << ": " << dat.second << std::endl;
    // }
    byr = atoi(inputData["byr"].c_str());
    iyr = atoi(inputData["iyr"].c_str());
    eyr = atoi(inputData["eyr"].c_str());
    hgt = inputData["hgt"];
    hcl = inputData["hcl"];
    ecl = inputData["ecl"];
    pid = inputData["pid"];
    cid = atoi(inputData["cid"].c_str());
}

inline std::map<std::string, std::string> Passport::handleInput(std::string rawInput) {
    std::stringstream ss(rawInput);
    std::string line;

    std::map<std::string, std::string> structuredInput;
    while (getline(ss, line, ' ')) {
        if (line.empty())
            continue;

        std::stringstream ss2(line);
        vector<std::string> valuePair;
        while (getline(ss2, line, ':')) {
            valuePair.push_back(line);
        }
        structuredInput.insert(pair<std::string, std::string>(valuePair[0], valuePair[1]));
    }

    return structuredInput;
}

bool Passport::validatePassportBasic(bool cidValid) {
    bool passwordValidates = false;
    int missingFileds = 0;

    missingFileds += byr == 0;
    missingFileds += iyr == 0;
    missingFileds += eyr == 0;
    missingFileds += hgt == "";
    missingFileds += hcl == "";
    missingFileds += ecl == "";
    missingFileds += pid == "";
    if (!cidValid) {
        missingFileds += cid == 0;
    }

    passwordValidates = (missingFileds == 0) ? true : false;

    return passwordValidates;
}

bool Passport::validatePassport(bool cidValid) {
    bool passwordValidates = false;
    int nonvalidFileds = 0;

    nonvalidFileds += byr < 1920 || byr > 2002;
    // cout << "byr: " << (byr < 1920 || byr > 2002) << ", " << std::flush;
    nonvalidFileds += iyr < 2010 || iyr > 2020;
    // cout << "iyr: " << (iyr < 2010 || iyr > 2020) << ", " << std::flush;
    nonvalidFileds += eyr < 2020 || eyr > 2030;
    // cout << "eyr: " << (eyr < 2020 || eyr > 2030) << ", " << std::flush;

    nonvalidFileds += !Passport::validateHeight();
    // cout << "hgt: " << !Passport::validateHeight() << ", " << std::flush;
    nonvalidFileds += !Passport::validateHairColor();
    // cout << "hcl: " << !Passport::validateHairColor() << ", " << std::flush;
    nonvalidFileds += !Passport::validateEyeColor();
    // cout << "ecl: " << !Passport::validateEyeColor() << ", " << std::flush;
    nonvalidFileds += !Passport::validatePassportID();
    // cout << "pid: " << !Passport::validatePassportID() << ", " << std::flush;

    if (cidValid) {
        nonvalidFileds += !Passport::validateCountryID();
    }

    // std::cout << "Fields:" << nonvalidFileds << std::endl;

    passwordValidates = (nonvalidFileds == 0) ? true : false;

    return passwordValidates;
}

inline bool Passport::validateHeight(){
    int height;
    if (hgt == "" || hgt.length() < 4) {
        return false;
    } else if (hgt.substr(hgt.length() - 2) == "in") {
        std::string heightNumber = hgt.substr(0, hgt.length() - 2);
        height = atoi(heightNumber.c_str());
        return height >= 59 && height <= 76;
    } else if (hgt.substr(hgt.length() - 2) == "cm") {
        std::string heightNumber = hgt.substr(0, hgt.length() - 2);
        height = atoi(heightNumber.c_str());
        return height >= 150 && height <= 193;
    } else {
        return false;
    }
}

inline bool Passport::validateHairColor(){
    if (hcl == "" || hcl.length() != 7 || hcl[0] != '#') {
        return false;
    } else {
        return std::all_of(hcl.begin() + 1, hcl.end(), [](char ch) { return (isdigit(ch) || (ch >= 'a' && ch <= 'f')); });
    }
}
inline bool Passport::validateEyeColor(){
    std::set<std::string> validEyeColors{"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};

    if (validEyeColors.find(ecl) != validEyeColors.end())
        return true;

    return false;
}
inline bool Passport::validatePassportID(){
    if (pid == "" || pid.length() != 9) {
        return false;
    } else {
        return std::all_of(pid.begin(), pid.end(), [](char ch) { return isdigit(ch); });
    }
}
inline bool Passport::validateCountryID(){
    return true;
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

#endif //_PASSWORD_H_