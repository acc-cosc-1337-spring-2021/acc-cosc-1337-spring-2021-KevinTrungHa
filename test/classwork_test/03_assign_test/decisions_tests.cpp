#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "loops.h"
#include "decision.h"



TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}


// test get_letter_grade_using_if function
TEST_CASE ("Test get letter grade using if function") 
{
	REQUIRE(get_letter_grade_using_if(95) == "A");
	REQUIRE(get_letter_grade_using_if(85) == "B");
	REQUIRE(get_letter_grade_using_if(75) == "C");
	REQUIRE(get_letter_grade_using_if(65) == "D");
	REQUIRE(get_letter_grade_using_if(50) == "F");
}


// test get_letter_grade_using_switch function
TEST_CASE ("Test get letter grade using switch function") 
{
	REQUIRE(get_letter_grade_using_switch(95) == "A");
	REQUIRE(get_letter_grade_using_switch(85) == "B");
	REQUIRE(get_letter_grade_using_switch(75) == "C");
	REQUIRE(get_letter_grade_using_switch(65) == "D");
	REQUIRE(get_letter_grade_using_switch(50) == "F");
}