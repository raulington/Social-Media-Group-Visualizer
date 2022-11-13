#pragma once
#include <vector>
#include <string>
#include <unordered_map>

/**
 * NOTE: The graph will likely be stored as a map from string to a vector of strings
 * Date Modified: 11/12/2022
 */
class Between {
    public:
    Between(std::unordered_map<std::string, std::vector<std::string>> map);
    std::unordered_map<std::string, double> centralities();

    private:
    double centrality(std::string s);
    std::unordered_map<std::string, std::vector<std::string>> map_;
    std::vector<std::pair<std::string, std::string>> vertex_pairs_;
    std::unordered_map<std::pair<std::string, std::string>, std::vector<std::vector<std::string>>> vertex_paths_;
};