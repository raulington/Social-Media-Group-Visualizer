#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Dijkstra.h"
#include "Between.h"
#include "GraphTraversal.h"
#include "BFS.h"
#include "DFS.h"

int main() {
    std::string tmp2;
    std::string tmp3;
    std::string tmp4;
    std::unordered_map<std::string, std::vector<std::string>> map;
    std::ifstream file("../facebook_combined.txt");

    int counter = 0;
    while (getline(file, tmp2)) {
        
        if (counter == 1000) {
            break;
        }
        tmp3 = tmp2.substr(0, tmp2.find(" "));
        tmp4 = tmp2.substr(tmp2.find(" ")+1, tmp2.size());
        map[tmp3].push_back(tmp4);
        map[tmp4].push_back(tmp3);
        counter++;

    }

    // Grab most Influential person
    Between b(map);
    std::unordered_map<std::string, double> centralities = b.centralities();
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
    int random_idx1 = rand() % map.size();
    int count = 0;
    std::string random_person1;
    for (const auto& pair : map) {
        count++;
        if (count == random_idx1) {
            random_person1 = pair.first;
            break;
        }
    }

    std::cout << "Random Person: " << random_person1 << std::endl;
    // performing BFS from most_influential to random_person1
    BFS bfs(map, random_person1, centralities.size());

    if (bfs.empty() == true) {
        std::cout << "EMPTY" << std::endl;
    }

    //printing out the path between the 2
    GraphTraversal::Iterator it;
    it = bfs.begin();
    while (it != bfs.end()) {

        if (*it == most_influential) {
            std::cout << *it << std::endl;
            break;
        }
        std::cout << *it << std::endl;
        ++it;
    }

    Dijkstra d(map);
    std::vector<std::string> d_path = d.shortest_path(most_influential, random_person1)[0];

    std::cout << "Path from most influential to random person using Dijkstra:" << std::endl;
    for (std::string step : d_path) {
        std::cout << step << std::endl;
    }
    

    file.close();
}