#pragma once

#include <iterator>
#include <cmath>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

#include "GraphTraversal.h"

/**
 * A depth-first GraphTraversal.
 * Derived from base class GraphTraversal
 * NOTE: The graph will likely be stored as a map from string to a vector of strings
 * Author: Sreyansh Mamidi
 * Date Modified: 11/11/2022
 */
class DFS : public GraphTraversal {
public:
  // DFS constructor
  DFS(const std::map<std::string, std::vector<std::string>>& graph, const std::string& start, int num_nodes);

  GraphTraversal::Iterator begin();
  GraphTraversal::Iterator end();

  void add(const std::string& node);
  std::string pop();
  std::string peek() const;
  bool empty() const;

private:
  // DFS
  std::stack<std::string> nodes_to_visit_;
  std::vector<std::string> nodes_visited_;

  // Graph
  std::map<std::string, std::vector<std::string>> graph_;
  std::string start_;
  int num_nodes_;

};
