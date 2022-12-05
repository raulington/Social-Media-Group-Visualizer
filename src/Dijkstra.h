#pragma once
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

class Dijkstra {
    public:
    Dijkstra(std::unordered_map<std::string, std::vector<std::string>>& map): map_(map) {};
    // std::vector<std::vector<std::string>> algorithm(std::string vertex1, std::string vertex2);
    std::vector<std::vector<std::string>> shortest_path(std::string vertex1, std::string vertex2);
    std::vector<std::vector<std::string>> shortest_paths(std::string source, std::string target);
    private:
    std::unordered_map<std::string, std::vector<std::string>> map_;
};