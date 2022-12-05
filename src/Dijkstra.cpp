#include "Dijkstra.h"
#include <iostream>
#include "PriorityQueue.h"
#include<bits/stdc++.h>
#include <climits>

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

std::vector<std::vector<std::string>> Dijkstra::shortest_paths(std::string source, std::string target) {
    std::vector<std::vector<std::string>> paths = shortest_path(source, target);
    std::vector<std::pair<std::string,std::string>> visited_edges;
    if (paths.empty() || paths[0].size() <= 2) return paths;
    size_t min = paths[0].size();
    size_t k = 0;
    while (k < paths.size()) {
        std::vector<std::string> current_path = paths[k];
        for (size_t i = 0; i < current_path.size() - 2; i++) {
            std::string node1 = current_path[i];
            std::string node2 = current_path[i+1];
            auto pair1 = std::make_pair(node1, node2);
            if (std::find(visited_edges.begin(), visited_edges.end(), pair1) != visited_edges.end()) continue;
            auto pair2 = std::make_pair(node2, node1);
            visited_edges.push_back(pair1);
            visited_edges.push_back(pair2);
            std::vector<std::string>& s_neighbors = map_.at(node1);
            std::vector<std::string>& t_neighbors = map_.at(node2);
            s_neighbors.erase(std::find(s_neighbors.begin(), s_neighbors.end(), node2));
            t_neighbors.erase(std::find(t_neighbors.begin(), t_neighbors.end(), node1));
            std::vector<std::vector<std::string>> test_path = shortest_path(source, target);
            s_neighbors.push_back(node2);
            t_neighbors.push_back(node1);
            if (!test_path.empty() 
                && (std::find(test_path[0].begin(), test_path[0].end(), source) == test_path[0].end() 
                || std::find(test_path[0].begin(), test_path[0].end(), target) == test_path[0].end())) {
                continue;
            }
            if (!test_path.empty() && test_path[0].size() == min
                && std::find(paths.begin(), paths.end(), test_path[0]) == paths.end()) {
                paths.push_back(test_path[0]);
            }
        }
        k++;
    }
    return paths;
}