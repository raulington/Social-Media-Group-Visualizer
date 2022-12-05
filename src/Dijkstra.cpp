#include "Dijkstra.h"
#include <iostream>
#include "PriorityQueue.h"
#include<bits/stdc++.h>

// std::vector<std::vector<std::string>> Dijkstra::algorithm(std::string vertex1, std::string vertex2) {
//     std::unordered_map<std::string, std::string> tmp;
//     std::queue<std::string> queue;
//     for (auto i : map_[vertex1]) {
//         queue.push(i);
//     }
//     std::vector<std::string> tmp2;
//     std::string tmp3;

//     while(queue.empty() == false) {
//         tmp3 = queue.front();
//         queue.pop();
//         for (auto i : map_[tmp3]) {
//             bool flag = true;
//             for (auto j : tmp2) {
//                 if (i == j) {
//                     flag = false;
//                     break;
//                 }
//             }
//             if (flag == true) {
//                 tmp[i] = tmp3;
//                 queue.push(i);
//             }
//         }
//         tmp2.push_back(tmp3);
//     }
//     std::vector<std::vector<std::string>> tmp4;
//     std::vector<std::string> tmp5;
//     std::string tmp6;
//     for (auto i : tmp) {
//         tmp6 = i.second;
//         tmp5.clear();
//         tmp5.push_back(i.first);
//         tmp5.push_back(i.second);
//         while (tmp.find(tmp6) != tmp.end()) {
//             tmp5.push_back(tmp6);
//             tmp6 = tmp[tmp6];
//         }
//         tmp5.push_back(tmp6);
//         tmp4.push_back(tmp5);
//     }
//     return tmp4;
// }

std::vector<std::vector<std::string>> Dijkstra::shortest_path(std::string source, std::string target) {
    std::unordered_map<std::string, int> weight;
    std::unordered_map<std::string, std::string> prev;
    for (auto i : map_) {
        weight[i.first] = 2;
        prev[i.first] = "";
    }
    weight[source] = 0;
    PriorityQueue queue;
    queue.buildheap(weight);
    std::vector<std::string> visited; //tmp3
    std::vector<std::vector<std::string>> to_return;
    while (queue.isempty() == false) {
        std::string u = queue.peek(); //tmp4
        visited.push_back(u);
        for (auto v : map_[u]) {
            auto it = std::find(visited.begin(), visited.end(), v);
            if (it != visited.end()) continue;
            visited.push_back(v);
            if (weight[v] == 2) {
                weight[v] = 1;
                prev[v] = u;
                if (v == target) {
                    std::vector<std::string> path; //tmp6
                    std::string current = v; //tmp7
                    while (prev.find(current) != prev.end()) {
                        path.push_back(current);
                        current = prev[current];
                    }
                    path.push_back(current);
                    if (to_return.empty()) {
                        to_return.push_back(path);
                        continue;
                    }
                    if (path.size() < to_return.at(0).size()) {
                        to_return.clear();
                        to_return.push_back(path);
                        continue;
                    }
                    if (path.size() == to_return.at(0).size()) {
                        to_return.push_back(path);
                        continue;
                    }
                }
            }
        }
        u = queue.pop(weight);
    }
    return to_return;
}