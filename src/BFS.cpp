#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "BFS.h"

using namespace std;

//constructor
BFS::BFS(const std::unordered_map<std::string, std::vector<std::string>> & graph_map, const std::string & start_point, size_t node_count) {
    size = node_count;
    graph = graph_map;
    start = start_point;

    //push point to the queue
    queue.push(start);

    //add the start to the list of visited points
    visited_vect.resize(size);
    visited_vect.push_back(start);
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
GraphTraversal::Iterator BFS::begin() {
    return GraphTraversal::Iterator();
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
GraphTraversal::Iterator BFS::end() {
    return GraphTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void BFS::add(const std::string & point) {
    //check  = TRUE if point needs to be added to vector
    //check = FALSE if point already exists in vector
    bool check = true;
    //check if the point has already been visited
    for (size_t i = 0; i < visited_vect.size(); ++i) {
        if (visited_vect.at(i) == point) {
            check = false;
            break;
        }
    }
    if (check == true) {
        //add the value
        queue.push(point);
        // add point to the visited vector
        visited_vect.push_back(point);
    }
}

/**
 * Removes and returns the current Point in the traversal.
 */
std::string BFS::pop() {
    std::string top = queue.front();
    queue.pop();
    return top;
}

/**
 * Returns the current Point in the traversal.
 */
std::string BFS::peek() const {
    return queue.front();
}

/**
 * Returns true if the traversal is empty.
 */
bool BFS::empty() const {
    return queue.empty();
}
