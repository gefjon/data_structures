#define CATCH_CONFIG_MAIN

#include <memory>
#include <cstdint>
#include "../catch.hpp"
#include "queue.hpp"

using namespace Queue;

TEST_CASE( "Enqueue and Length", "[Queue]" ) {
  auto queue = std::make_unique< Queue< std::uint32_t > >();
  CHECK( queue->Length() == 0 );

  for (std::uint32_t i = 0; i < 16; i++) {
    REQUIRE_NOTHROW( queue->Enqueue(i) );
    REQUIRE( queue->Length() == i + 1 );
  }

  CHECK( queue->Length() == 16 );
}

TEST_CASE( "Enqueue and Dequeue", "[Queue]" ) {
  auto queue = std::make_unique< Queue< std::uint32_t > >();
  for (std::uint32_t i = 0; i < 16; i++) {
    REQUIRE_NOTHROW( queue->Enqueue(i) );
  }
  
  for (std::uint32_t i = 0; i < 16; i++) {
    CHECK( queue->Peek() == i );
    CHECK( queue->Dequeue() == i );
  }
}

TEST_CASE( "Error on underflow in Dequeue", "[Queue]" ) {
  auto queue = std::make_unique< Queue< std::uint32_t > >();
  REQUIRE_THROWS( queue->Dequeue() );
}

TEST_CASE( "Error on underflow in Peek", "[Queue]" ) {
  auto queue = std::make_unique< Queue< std::uint32_t > >();
  REQUIRE_THROWS( queue->Peek() );
}
