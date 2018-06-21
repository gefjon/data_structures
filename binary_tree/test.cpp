#define CATCH_CONFIG_MAIN

#include "../catch.hpp"
#include "binary_tree.hpp"
#include <tuple>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

typedef int Key;
typedef std::string Value;
typedef std::tuple< Key, Value > Elem;

bool MapCmp(Elem const& left, Elem const& right) {
  return std::get<0>(left) < std::get<0>(right);
}

bool MapEq(Elem const& left, Elem const& right) {
  return std::get<0>(left) == std::get<0>(right);
}

bool TreeCmp(unsigned int const& left, unsigned int const& right) {
  return left < right;
}

bool TreeEq(unsigned int const& left, unsigned int const& right) {
  return left == right;
}

typedef BinaryTree::BTree< Elem, MapCmp, MapEq > BMap;
typedef BinaryTree::BTree< unsigned int, TreeCmp, TreeEq > Tree;

TEST_CASE( "Simple unsigned int tree", "[BTree]" ) {  
  Tree tree;
  tree.Insert(0xdeadbeef);
  tree.Insert(0xffffffff);
  tree.Insert(0x0);

  CHECK( tree.Search(0xdeadbeef)->Elem() == 0xdeadbeef );
  CHECK( tree.Search(0xffffffff)->Elem() == 0xffffffff );
  CHECK( tree.Search(0x0)->Elem() == 0x0 );
}

TEST_CASE( "Map of (int, string)", "[BTree]" ) {
  BMap map;
  map.Insert(std::make_tuple(5, std::string("Five")));
  map.Insert(std::make_tuple(2, std::string("Two")));
  map.Insert(std::make_tuple(7, std::string("Seven")));

  CHECK(
        std::get<1>(
                    map.Search(
                                 std::make_tuple(5, std::string())
                               )->Elem()
                      )
        .compare("Five") == 0
        );


  CHECK(
        std::get<1>(
                    map.Search(
                                 std::make_tuple(7, std::string())
                               )->Elem()
                    )
        .compare("Seven") == 0
        );

  CHECK(
        std::get<1>(
                    map.Search(
                                 std::make_tuple(2, std::string())
                               )->Elem()
                    )
        .compare("Two") == 0
        );
}

TEST_CASE( "Remove least element from BTree", "[BTree]" ) {
  std::vector< unsigned int > ints;
  for (unsigned int i = 0; i < 10; i++) {
    ints.push_back(i);
  }
  
  std::random_shuffle(ints.begin(), ints.end());

  std::vector< unsigned int >::iterator iter;

  Tree tree;
  for (iter = ints.begin(); iter != ints.end(); iter++) {
    tree.Insert(*iter);
  }

  for (unsigned int i = 0; i < 10; i++) {
    CHECK( tree.RemoveLeast() == i );
  }
}
