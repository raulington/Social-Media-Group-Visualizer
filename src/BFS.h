#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>

#include "GraphTraversal.h"

/**
 * A breadth-first GraphTraversal.
 * Derived from base class GraphTraversal
 */
class BFS : public GraphTraversal {
public:
  BFS(const std::unordered_map<std::string, std::vector<std::string>> & graph_map, const std::string & start_point, size_t node_count);

  GraphTraversal::Iterator begin();
  GraphTraversal::Iterator end();

  void add(const std::string & point);
  std::string pop();
  std::string peek() const;
  bool empty() const;

private:
  size_t size;
  std::queue<std::string> queue;
  std::vector<std::string> visited_vect;
  std::string start; //where we start the traversal
  
  std::unordered_map<std::string, std::vector<std::string>> graph;
  
};
