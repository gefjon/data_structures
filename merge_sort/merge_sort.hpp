#pragma once

#define MERGE_SORT_COMPARATOR(T, name) bool(*name)(T const&, T const&)

#include <vector>
#include <utility>

namespace MergeSort {

  template< class T >
  bool Lt(T const&, T const&);
  
  template< class T, MERGE_SORT_COMPARATOR(T, LT) = Lt< T > >
  void sort(
            std::vector< T >&,
            typename std::vector< T >::size_type,
            typename std::vector< T >::size_type
            );

  template< class T, MERGE_SORT_COMPARATOR(T, LT) = Lt< T > >
  void merge(
              std::vector< T >&,
              typename std::vector< T >::size_type,
              typename std::vector< T >::size_type,
              typename std::vector< T >::size_type
             );

  template< class T, MERGE_SORT_COMPARATOR(T, LT) = Lt< T > >
  void sort(std::vector< T >&);
}

#include "merge_sort.tpp"
