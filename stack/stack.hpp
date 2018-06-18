#pragma once

#include <memory>
#include <cstddef>
#include <array>
#include <utility>
#include <exception>
#include <string>
#include <sstream>

namespace Stack {
  class IndexOutOfRangeException : public std::exception {
  public:
    using index = std::size_t;
  private:
    index attempted_idx_;
    index highest_legal_idx_;
    index max_size_;
    std::string description_;
  public:
    IndexOutOfRangeException(index, index, index);
    char const* what() const throw() {
      return this->description_.c_str();
    }
  };
  
  template< class T, size_t SIZE >
  class Stack {
    std::array< T, SIZE > backing_array_;
    std::size_t length_ = 0;

  public:
    using index = std::size_t;

    
    Stack();
    Stack(const Stack< T, SIZE >&);
    ~Stack();

    index Size();
    index MaxSize();

    index Length();
    index HighestLegalIndex();

    T& Push(T);
    T& Peek();
    T Pop();

    T& operator[](index);
    T& at(index);
  };
}

#include "stack.tpp"
