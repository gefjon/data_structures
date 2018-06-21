#include "heap_sort.hpp"

bool HeapSort::IntDecreasingCmp(int const& left, int const& right) {
  return left > right;
}

bool HeapSort::IntIncreasingCmp(int const& left, int const& right) {
  return left < right;
}

bool HeapSort::IntEq(int const& left, int const& right) {
  return left == right;
}
