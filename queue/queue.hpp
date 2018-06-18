#pragma once

#include "../linked_list/linked_list.hpp"
#include <memory>
#include <utility>
#include <exception>

namespace Queue {
  struct UnderflowException : public std::exception {
    UnderflowException() {};
    char const* what() const throw() {
      return "Attempt to Dequeue or Peek from an empty Queue";
    }
  };
  
  template< class T >
  class Queue {
    std::shared_ptr< LinkedList::Node< T > > head_;
    std::shared_ptr< LinkedList::Node< T > > tail_;
    unsigned int length_ = 0;

    bool head_is_defined();
    bool tail_is_defined();
    void assert_defined();

  public:
    Queue();
    Queue(const Queue< T >&);
    ~Queue();

    void Enqueue(T);
    T Dequeue();
    T& Peek();

    unsigned int Length();
  };
}

#include "queue.tpp"
    
