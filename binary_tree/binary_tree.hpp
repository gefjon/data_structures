#pragma once

#include <memory>
#include <utility>
#include <cassert>

#define BTREE_COMPARATOR(T, name) bool(*name)(T const&, T const&)

namespace BinaryTree {
  struct SearchFailureException : public std::exception {
    SearchFailureException() {};
    char const* what() const throw() {
      return "Did not find an element while searching a BTree";
    }
  };
  struct EmptyBTreeException : public std::exception {
    EmptyBTreeException() {};
    char const* what() const throw() {
      return "Attempted to remove from an empty BTree";
    }
  };
  
  template< class T, BTREE_COMPARATOR(T, LT), BTREE_COMPARATOR(T, EQ) >
  class BTree {
  public:
    
    class Node {
      T elem_;
      std::shared_ptr< Node > left_;
      std::shared_ptr< Node > right_;
    public:
      Node();
      Node(T);
      Node(Node const&);
      ~Node();
      T& Elem();
      std::shared_ptr< Node >& Left();
      std::shared_ptr< Node >& Right();
      bool HasChild();
    };
    
    BTree();
    ~BTree();
    std::shared_ptr< Node > Search(T const&);
    void Insert(T);
    T RemoveLeast();
    operator bool() const noexcept;
  private:
    T RemoveLeast(std::shared_ptr< Node >& parent);
    std::shared_ptr< Node > root_;
    //    std::shared_ptr< Node >& Search(T const&, std::shared_ptr< Node >&);
  };
}

#include "binary_tree.tpp"
