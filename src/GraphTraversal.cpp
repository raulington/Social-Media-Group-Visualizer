#include <cmath>
#include <iterator>
#include <iostream>

#include "GraphTraversal.h"



/**
 * Default iterator constructor.
 */
GraphTraversal::Iterator::Iterator() {}
GraphTraversal::Iterator::Iterator(GraphTraversal * g) {}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
GraphTraversal::Iterator & GraphTraversal::Iterator::operator++() {
    return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the GraphTraversal.
 */
std::string GraphTraversal::Iterator::operator*() {
    return "";
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool GraphTraversal::Iterator::operator!=(const GraphTraversal::Iterator &other) {
    return true;
}

