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
}

TEST_CASE("copying array", "[array2d]") {
	fsl::array2d<int> a{ 3, 4 };
	a(0, 0) = 1;
	fsl::array2d<int> copiedArray(a);
	REQUIRE(copiedArray.columns() == 4);
	REQUIRE(copiedArray.rows() == 3);
	REQUIRE(!copiedArray.empty());
	REQUIRE(copiedArray[0][0] == 1);
}

TEST_CASE("swapping array", "[array2d]") {
	fsl::array2d<int> a{ 3, 4 };
	fsl::array2d<int> otherArray{2,3};
	a(0, 0) = 1;
	REQUIRE(otherArray(0, 0) == 0);
	REQUIRE(otherArray.columns() == 3);
	REQUIRE(otherArray.rows() == 2);
	REQUIRE(!otherArray.empty());
	a.swap(otherArray);
	REQUIRE(otherArray.columns() == 4);
	REQUIRE(otherArray.rows() == 3);
	REQUIRE(otherArray[0][0] == 1);
	REQUIRE(a(0, 0) == 0);
	REQUIRE(a.columns() == 3);
	REQUIRE(a.rows() == 2);
}

TEST_CASE("paren operator", "[array2d]") {
	fsl::array2d<int> a{ 3, 4 };
	REQUIRE(a(0, 0) == 0);
	a(0, 0) = 1;
	REQUIRE(a(0, 0) == 1);
	a(2, 3) = 1;
	REQUIRE(a(2, 3) == 1);
}

TEST_CASE("square bracket operator", "[array2d]") {
	fsl::array2d<int> a{ 3, 4 };
	REQUIRE(a[0][0] == 0);
	a[0][0] = 1;
	REQUIRE(a[0][0] == 1);
	a[2][3] = 1;
	REQUIRE(a[2][3] == 1);
}

TEST_CASE("paren and square bracket equivalence", "[array2d]") {
	fsl::array2d<int> a{ 3, 4 };
	REQUIRE(a[0][0] == 0);
	a(0, 0) = 1;
	REQUIRE(a[0][0] == 1);
	a[2][3] = 1;
	REQUIRE(a(2, 3) == 1);
}


// Add other TEST_CASEs to test operator[], copying the array, swap, etc.
