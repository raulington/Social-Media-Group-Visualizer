#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

/**
 * NOTE: The graph will likely be stored as a map from string to a vector of strings
 * Date Modified: 11/12/2022
 */
class Between {
    public:
    Between(std::unordered_map<std::string, std::vector<std::string>>& graph);
    std::unordered_map<std::string, double> centralities();

    private:
    std::unordered_map<std::string, std::vector<std::string>> graph_;
};