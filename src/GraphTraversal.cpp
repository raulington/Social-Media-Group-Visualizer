#include <cmath>
#include <iterator>
#include <iostream>

#include "GraphTraversal.h"



/**
 * Default iterator constructor.
 */
GraphTraversal::Iterator::Iterator() : graph_traversal(NULL) {
    // Do nothing
}

GraphTraversal::Iterator::Iterator(GraphTraversal * g, std::string start) : graph_traversal(g), start(start) {
    // set the value for start
    //start = g->peek();
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
GraphTraversal::Iterator & GraphTraversal::Iterator::operator++() {

    //check if there is content present
    if (!graph_traversal->empty()) {
        start = graph_traversal->pop();
        graph_traversal->add(start);
        start = graph_traversal->peek();
    }
    return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the GraphTraversal.
 */
std::string GraphTraversal::Iterator::operator*() {
    return start;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool GraphTraversal::Iterator::operator!=(const GraphTraversal::Iterator &other) {

    bool empty = false;
    bool other_empty = false;

    if (graph_traversal == NULL) {
        empty = true;
    }
    if (other.graph_traversal == NULL) {
        other_empty = true;
    }
    if (!empty) {
        empty = graph_traversal->empty();
    }
    if (!other_empty) {
        other_empty = other.graph_traversal->empty();
    }
    if (empty && other_empty) {
        return false;
    } else if ((!empty)&&(!other_empty)) {
        return (graph_traversal != other.graph_traversal);
    } else {
        return true;
    } 
}

