#include "fsl/array2d.hh"
#include "catch/catch.hpp"
#include <iostream>

TEST_CASE("Empty arrays have certain properties", "[array2d]") {
  fsl::array2d<int> a{};
  REQUIRE(a.empty());
}

TEST_CASE("Non-empty arrays have certain properties", "[array2d]") {
  fsl::array2d<int> a{3, 4};
  REQUIRE(a.columns() == 4);
  REQUIRE(a.rows() == 3);
  REQUIRE(!a.empty());
  //int test = a[0][0];
  //REQUIRE(test == 0);
  int test = a(0, 0);
  REQUIRE(test == 0);
  a(0, 0) = 1;
  REQUIRE(a(0, 0) == 1);
  test = a[0][1];
  REQUIRE(test == 0);
  a[0][1] = 1;
  test = a[0][1];
  REQUIRE(test == 1);
  //fsl::array2d<int> copiedArray(a);
  //REQUIRE(copiedArray.columns() == 4);
  //REQUIRE(copiedArray.rows() == 3);
  //REQUIRE(!copiedArray.empty());
  //test = copiedArray[0][0];
  //REQUIRE(test == 0);
  //copiedArray[0][0] = 1;
 // a.swap(copiedArray);
  //test = a[0][0];
  //REQUIRE(test == 1);
}

// Add other TEST_CASEs to test operator[], copying the array, swap, etc.
