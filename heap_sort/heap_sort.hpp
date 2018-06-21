#pragma once

#include "../binary_tree/binary_tree.hpp"
#include <vector>

namespace HeapSort {
  template<
    class T,
    class I,
    BTREE_COMPARATOR(T, LT),
    BTREE_COMPARATOR(T, EQ)
    >
  std::vector< T > Sort(I begin, I end);

  template< class I >
  std::vector< int > IntDecreasing(I begin, I end);

  template< class C >
  std::vector< int > IntIncreasing(C const&);

  bool IntDecreasingCmp(int const&, int const&);
  bool IntIncreasingCmp(int const&, int const&);
  bool IntEq(int const&, int const&);
}

#include "heap_sort.tpp"
