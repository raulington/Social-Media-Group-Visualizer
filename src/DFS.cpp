#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "DFS.h"

/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * 
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */
DFS::DFS(const std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& start, int num_nodes) : graph_(graph), start_(start), num_nodes_(num_nodes) { 
    nodes_visited_.resize(num_nodes_);
    nodes_to_visit_.push(start);
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
GraphTraversal::Iterator DFS::begin() {
    return GraphTraversal::Iterator();
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
GraphTraversal::Iterator DFS::end() {
    return GraphTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const std::string& node) {
    // Makes sure node is not visited before it's added to the stack
    bool not_visited = std::find(nodes_visited_.begin(), nodes_visited_.end(), node) == nodes_visited_.end();
    if (not_visited) {
        nodes_to_visit_.push(node);
        nodes_visited_.push_back(node);
    }   
}

/**
 * Removes and returns the current Point in the traversal.
 */
std::string DFS::pop() {
    std::string top_node = nodes_to_visit_.top();
    nodes_to_visit_.pop();
    return top_node;
}

/**
 * Returns the current Point in the traversal.
 */
std::string DFS::peek() const {
    return nodes_to_visit_.top();
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
    return nodes_to_visit_.empty();
}
