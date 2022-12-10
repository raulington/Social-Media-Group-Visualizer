#include "Between.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

Between::Between(std::unordered_map<std::string, std::vector<std::string>>& graph) {
    graph_ = graph;
}

// Pseudocode from https://sites.cs.ucsb.edu/~gilbert/cs240a/Old/cs240aSpr2011/slides/RobinsonBCslides.pdf
std::unordered_map<std::string, double> Between::centralities()
{
    // Initialize the betweenness centrality of all nodes to 0
    std::unordered_map<std::string, double> bc;
    for (const auto& pair : graph_) {
        auto node = pair.first;
        bc[node] = 0.0;
    }

    // Iterate over all nodes in the graph
    for (const auto& pair : graph_) {
        auto source = pair.first;
        // Queue for storing the nodes visited during the breadth-first search
        std::queue<std::string> Q; Q.push(source);
        std::stack<std::string> S;

        std::unordered_map<std::string, double> sig;
        std::unordered_map<std::string, int> d;
        for (const auto& pair2 : graph_) {
            std::string node = pair2.first;
            d[node] = -1;
            sig[node] = 0;
        }
        sig[source] = 1;
        d[source] = 0;

        // Maps from a node to its predecessor nodes on the shortest path from the source node
        std::unordered_map<std::string, std::vector<std::string>> P;
        for (const auto& pair3 : graph_) {
            std::string node = pair3.first;
            P[node] = {};
        }

        // Perform breadth-first search
        while (!Q.empty()) {
            std::string v = Q.front(); Q.pop();
            S.push(v);
            for (std::string w : graph_.at(v)) {
                if (d[w] < 0) {
                    Q.push(w);
                    d[w] = d[v] + 1;
                }
                if (d[w] == d[v] + 1) {
                    sig[w] = sig[w] + sig[v];
                    P[w].push_back(v);
                }
            }
        }
        std::unordered_map<std::string, double> z;
        for (const auto& pair4 : graph_) {
            auto node = pair4.first;
            z[node] = 0.0;
        }
        
        while (!S.empty()) {
            std::string w = S.top(); S.pop();
            for (auto& v : P[w]) {
                z[v] = z[v] + (sig[v] / sig[w]) * (1 + z[w]);
            }
            if (w != source) bc[w] = bc[w] + z[w];
        }
    }

    for (auto& pair : bc) {
        pair.second = pair.second/2;
    }
    return bc;
}                 