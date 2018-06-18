#define CATCH_CONFIG_MAIN

#include <memory>
#include <cstdint>
#include "../catch.hpp"
#include "stack.hpp"

using namespace Stack;

TEST_CASE( "Size of underlying array", "[Stack]" ) {
  auto stack = std::make_unique< Stack< std::uint32_t, 128 > >();
  CHECK( stack->Size() == 128 );
  CHECK( stack->MaxSize() == 128 );
}

TEST_CASE( "Index into a stack", "[Stack]" ) {
  auto stack = std::make_unique< Stack< std::size_t, 128 > >();

  SECTION( "Size of underlying array", "[Stack]" ) {
    CHECK( stack->Size() == 128 );
    CHECK( stack->MaxSize() == 128 );
  }

  SECTION( "Push values", "[Stack]" ) {
    for (std::size_t i = 0; i < 128; i++) {
      REQUIRE_NOTHROW( stack->Push(i) );
    }
  }

  SECTION( "Attempt legal indexes", "[Stack]" ) {
    for (std::size_t i = 0; i < 128; i++) {
      REQUIRE( (*stack)[i] == i );
      REQUIRE( stack->at(i) == i );
    }
  }

  SECTION( "Attempt an illegal index", "[Stack]" ) {
    REQUIRE_THROWS( stack->at(128) );
  }
}

TEST_CASE( "Push to a stack", "[Stack]" ) {
  auto stack = std::make_unique< Stack< std::uint32_t, 128 > >();
  stack->Push(0xdeadbeef);
  CHECK( stack->Peek() == 0xdeadbeef );
  CHECK( stack->Pop() == 0xdeadbeef );
}
