#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Between.h"
#include "GraphTraversal.h"

int main() {
    std::string tmp2;
    std::string tmp3;
    std::string tmp4;
    std::unordered_map<std::string, std::vector<std::string>> map;
    std::ifstream file("facebook_combined.txt");
    while (getline(file, tmp2)) {
        tmp3 = tmp2.substr(0, tmp2.find(" "));
        tmp4 = tmp2.substr(tmp2.find(" "), tmp2.size());
        map[tmp3].push_back(tmp4);
        map[tmp4].push_back(tmp3);
    }

    // Grab most Influential person
    Between b(map);
    std::unordered_map<std::string, double> centralities;
    int maxcentrality = 0;
    std::string most_influential;
    for (const auto& pair : centralities) {
        if (pair.second > maxcentrality) {
            most_influential = pair.first;
            maxcentrality = pair.second;
        }
    }

    std::cout << "Most influential person: " << most_influential << std::endl;

    // Grab random person
    int random_idx = rand() % map.size();
    int count = 0;
    std::string random_person;
    for (const auto& pair : map) {
        if (count == random_idx) {
            random_person = pair.first;
            break;
        }
    }
    file.close();
}