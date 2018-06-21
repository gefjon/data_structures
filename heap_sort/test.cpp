#define CATCH_CONFIG_MAIN

#include "../catch.hpp"
#include "heap_sort.hpp"
#include <algorithm>
#include <string>
#include <iostream>

TEST_CASE( "Sort a vector", "[HeapSort]" ) {
  std::vector< int > ints;
  ints.reserve(32);
  
  std::vector< int > increasing;
  increasing.reserve(32);
  for (int i = 0; i < 32; i++) {
    ints.push_back(i);
    increasing.push_back(i);
  }

  std::vector< int > decreasing;
  decreasing.reserve(32);
  for (int i = 31; i >= 0; i--) {
    decreasing.push_back(i);
  }

  std::random_shuffle(ints.begin(), ints.end());

  auto sorted = HeapSort::IntDecreasing(ints.begin(), ints.end());
  
  CHECK( sorted == decreasing );

  sorted = HeapSort::IntIncreasing(ints.begin(), ints.end());

  CHECK( sorted == increasing );
}

struct Person {
  unsigned int height_;
  std::string name_;
  Person(unsigned int height, std::string name)
    : height_(height)
    , name_(name)
  {}
  friend std::ostream& operator<<(std::ostream& os, Person const& person) {
    os << person.name_ << " (" << person.height_ << "cm)";
    return os;
  }
};

bool HeightLt(Person const& left, Person const& right) {
  return left.height_ < right.height_;
}

bool HeightEq(Person const& left, Person const& right) {
  return left.height_ == right.height_;
}

TEST_CASE( "Sort a vector of a more exotic type", "[HeapSort]" ) {
  std::vector< Person > people;
  people.push_back(Person(173, "Brett"));
  people.push_back(Person(200, "Andre"));
  people.push_back(Person(155, "Hanna"));

  auto sorted = HeapSort::Sort<
    Person,
    typename std::vector< Person >::iterator,
    HeightLt,
    HeightEq
    >(people.begin(), people.end());

  CHECK( sorted[0].name_ == "Hanna" );
  CHECK( sorted[1].name_ == "Brett" );
  CHECK( sorted[2].name_ == "Andre");
}
