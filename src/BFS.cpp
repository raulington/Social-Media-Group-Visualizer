#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "BFS.h"

using namespace cs225;


BFS::BFS() { }

/**
 * Returns an iterator for the traversal starting at the first point.
 */
GraphTraversal::Iterator BFS::begin() {}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
GraphTraversal::Iterator BFS::end() {}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void BFS::add(const Point & point) {}

/**
 * Removes and returns the current Point in the traversal.
 */
Point BFS::pop() {}

/**
 * Returns the current Point in the traversal.
 */
Point BFS::peek() const {}

/**
 * Returns true if the traversal is empty.
 */
bool BFS::empty() const {}
