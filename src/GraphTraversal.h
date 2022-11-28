/**
 * @file GraphTraversal.h
 */
#pragma once

#include <iterator>
#include <vector>
#include <string>

/**
 * A base class for traversal algorithms on images.
 *
 * BFS and DFS will inherit from this class
 * 
 * Each derived class must maintain an ordering of points on an image,
 * through calls to the virtual member functions `add` and `pop`.
 * 
 * A derived class provides a traversal by returning instances of
 * GraphTraversal::Iterator.
 */
class GraphTraversal {
public:
  /**
   * A forward iterator through an GraphTraversal.
   */
  class Iterator : std::iterator<std::forward_iterator_tag, std::string> {
  public:
    Iterator();
    Iterator(GraphTraversal* g);

    Iterator & operator++();
    std::string operator*();
    bool operator!=(const Iterator &other);

  private:
  };

  /**
   * The begining of an iterator
   * Virtual function. Derived class need to implement this
   */
  virtual Iterator begin() = 0;

  /**
   * The end of an iterator
   * Virtual function. Derived class need to implement this
   */
  virtual Iterator end() = 0;

  /**
   * Add new point to the traversal
   * Virtual function. Derived class need to implement this
   */
  virtual void add(const std::string & t) = 0;
  /**
   * Remove and return the next point of the traversal
   * Virtual function. Derived class need to implement this
   */
  virtual std::string pop() = 0;
  /**
   * Return but not remove the next point of the traversal
   * Virtual function. Derived class need to implement this
   */
  virtual std::string peek() const = 0;
  /**
   * To see if the traversal has no points left
   * Virtual function. Derived class need to implement this
   */
  virtual bool empty() const = 0;

private: 
};
