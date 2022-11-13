#pragma once
#include <string>
#include <vector>

class Dijkstra {
    public:
    Dijkstra(std::unordered_map<std::string, std::vector<std::string>> map): map_(map) {};
    std::vector<std::vector<std::string>> algorithm(std::string vertex1, std::string vertex2);

    private:
    std::unordered_map<std::string, std::vector<std::string>> map_;
};