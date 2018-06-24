#define CATCH_CONFIG_MAIN

#include "../catch.hpp"
#include "merge_sort.hpp"
#include <vector>
#include <algorithm>

TEST_CASE( "Merge some vectors", "[MergeSort][merge]" ) {
  std::vector< int > ints = { 0, 2, 4, 1, 3, 5 };

  REQUIRE_NOTHROW( MergeSort::merge(ints, 0, 2, 5) );

  std::vector< int > sorted;
  for (int i = 0; i < 6; i++) {
    sorted.push_back(i);
  }
  CHECK( sorted == ints );
}

TEST_CASE( "Sort a vector", "[MergeSort]" ) {
  std::vector< int > ints;
  ints.reserve(32);

  std::vector< int > increasing;
  increasing.reserve(32);
  
  for (int i = 0; i < 32; i++) {
    ints.push_back(i);
    increasing.push_back(i);
  }

  std::random_shuffle(ints.begin(), ints.end());

  REQUIRE_NOTHROW( MergeSort::sort(ints) );

  CHECK( ints == increasing );
}
