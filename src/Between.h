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
    //const std::unordered_map<std::string, std::vector<std::string>>& map
    Between(std::unordered_map<std::string, std::vector<std::string>>& graph);
    std::unordered_map<std::string, double> centralities();
    std::map<std::pair<std::string, std::string>, std::vector<std::vector<std::string>>> vertex_paths_;

    private:
    double centrality(std::string s);
    std::unordered_map<std::string, std::vector<std::string>> graph_;
    std::vector<std::pair<std::string, std::string>> vertex_pairs_;
};