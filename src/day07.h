//
// Created by AdamOttvar on 2020-12-07
//

#ifndef _DAY07_H_
#define _DAY07_H_

#include "common.h"
#include <map>
#include <set>
#include <sstream>
#include <vector>

void readLuggageRules(std::string, std::map<std::string, std::set<std::string>> &, std::map<std::string, std::vector<std::tuple<int, std::string>>> &);
void checkColorParents(std::string, std::map<std::string, std::set<std::string>> &, std::set<string> &);
long checkColorChildren(string, map<string, vector<tuple<int, string>>> &);
int day07(bool part_two = false);

#endif //_DAY07_H_