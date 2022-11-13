#include "Between.h"
#include "Dijkstra.h"
#include <algorithm>

Between::Between(std::unordered_map<std::string, std::vector<std::string>> map): map_(map) {
    // Storing all vertices from the map
    std::vector<std::string> vertices;
    for (const auto& keyvalue : map_) {
        vertices.push_back(keyvalue.first);
    }

    // Getting all possible pairs of vertices
    for (size_t i = 0; i < vertices.size() - 1; ++i)
        for (size_t j = i + 1; j < vertices.size(); j++)
            vertex_pairs_.push_back(std::make_pair(vertices[i], vertices[j]));

    // Getting all possible shortest paths
    Dijkstra d(map_);
    for (const auto& vertex_pair : vertex_pairs_) {
        std::vector<std::vector<std::string>> paths = d.algorithm(vertex_pair.first, vertex_pair.second);
        vertex_paths_.insert(std::make_pair(vertex_pair, paths));
    }
}

double Between::centrality(std::string s) {
    double centrality = 0;
    // Calculating centrality
    Dijkstra d(map_);
    for (const auto& vertex_pair : vertex_pairs_) {
        if (vertex_pair.first == s || vertex_pair.second == s) continue;
        std::vector<std::vector<std::string>> paths = vertex_paths_.at(vertex_pair);
        double size = paths.size();
        double count = 0;
        if (size > 0) {
            for (const auto& path : paths)
                if (std::find(path.begin(), path.end(), s) != path.end())
                    count += 1;
            count = count / size;
        }
        centrality += count;
    }
    
    return centrality;
}

std::unordered_map<std::string, double> Between::centralities() {
    std::unordered_map<std::string, double> all_centralities;
    for (const auto& keyvalue : map_) {
        all_centralities.insert(std::make_pair(keyvalue.first, centrality(keyvalue.first)));
    }
    return all_centralities;
}