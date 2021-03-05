#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "loops.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

//write the test case for the factorial function with values: 
//num 3 returns 6
//num 4 returns 24
//num 5 returns 120

TEST_CASE("Test case for the factorial function") {
	REQUIRE(factorial(3) == 6);
	REQUIRE(factorial(4) == 24);
	REQUIRE(factorial(5) == 120);
}