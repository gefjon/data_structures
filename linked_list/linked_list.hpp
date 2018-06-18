#pragma once

#include <utility>
#include <memory>

namespace LinkedList {
  template< class T >
  struct Node {
    T elem_;
    std::shared_ptr< Node< T > > next_;
    
    Node();
    Node(const Node< T >&);
    Node(T);
    Node(T, std::shared_ptr< Node< T > >);

    ~Node();

    Node< T >& operator=(const Node< T >&);

    T& Car();
    std::shared_ptr< Node< T > > Cdr();

    Node< T > Prepend(T);
  };
}

#include "linked_list.tpp"
