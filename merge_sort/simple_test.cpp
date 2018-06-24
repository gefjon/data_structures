#include <cassert>
#include <algorithm>
#include <vector>
#include "merge_sort.hpp"

int main() {
  std::vector< int > ints = { 0, 2, 4, 1, 3, 5 };

  assert( ints.size() == 6 );

  MergeSort::merge(ints, 0, 2, 5);

  std::vector< int > sorted = { 0, 1, 2, 3, 4, 5 };

  assert( ints == sorted );
}
