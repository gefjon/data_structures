#define CATCH_CONFIG_MAIN

#include <memory>
#include "../catch.hpp"
#include "linked_list.hpp"

using namespace LinkedList;

TEST_CASE( "Call a Node constructor", "[Node]" ) {
  auto n = std::make_unique< Node< int > >(3);
  REQUIRE( n->Car() == 3 );
}

TEST_CASE( "Copy-construct a Node", "[Node]" ) {
  auto first = std::make_unique< Node< int > >(3);
  Node< int > second = *first;
  REQUIRE( second.Car() == 3 );
}

TEST_CASE( "Build a list of two Nodes", "[Node]" ) {
  auto tail = std::make_shared< Node< int > >(2);
  auto head = std::make_shared< Node< int > >(1, tail);
  CHECK( head->Cdr() == tail );
  CHECK( head->Car() == 1);
  CHECK_FALSE( head->Cdr()->Cdr() );
}

TEST_CASE( "Car and Cdr", "[Node]" ) {
  auto node = std::make_unique< Node< int > >(2);
  CHECK( node->Car() == 2 );
  CHECK_FALSE( node->Cdr() );
}

TEST_CASE( "Prepend", "[Node]" ) {
  Node< int > tail = { 1, nullptr };
  Node< int > head = tail.Prepend(2);
  CHECK( head.Car() == 2);
  CHECK( head.Cdr()->Car() == 1);
}
