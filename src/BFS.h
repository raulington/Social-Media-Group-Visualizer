#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>


/**
 * A breadth-first GraphTraversal.
 * Derived from base class GraphTraversal
 */
class BFS : public GraphTraversal {
public:
  BFS(const PNG & png, const Point & start, double tolerance);

  ImageTraversal::Iterator begin();
  ImageTraversal::Iterator end();

  void add(const Point & point);
  Point pop();
  Point peek() const;
  bool empty() const;

private:
  
};
