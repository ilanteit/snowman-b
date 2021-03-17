#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

//C++20 -> version

// string nospaces(string input) {
// 	std::erase(input, ' ');
// 	std::erase(input, '\t');
// 	std::erase(input, '\n');
// 	std::erase(input, '\r');
// 	return input;
// }

//version C++11

string nospaces(string input)
{
	input.erase(remove(input.begin(), input.end(), ' '), input.end());
	input.erase(remove(input.begin(), input.end(), '\t'), input.end());
	input.erase(remove(input.begin(), input.end(), '\n'), input.end());
	input.erase(remove(input.begin(), input.end(), '\r'), input.end());
	return input;
}

TEST_CASE("Good snowman code")
{
	
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(22222222)) == nospaces(" ___ \n .....\n\\(o.o)/\n(] [)\n(\" \")\n"));
	CHECK(nospaces(snowman(33333333)) == nospaces("  _  \n /_\\ (O_O)\n(> <)\n/( ___ )\\"));
	CHECK(nospaces(snowman(44444444)) == nospaces(" ___ \n(_*_)\n(- -)\n(   )\n(   )"));
	CHECK(nospaces(snowman(12341234)) == nospaces("_===_\n(O.-)/\n<(> <)\n(  )"));
	CHECK(nospaces(snowman(43214321)) == nospaces(" ___ \n(_*_)\n(o_.)\n(] [)\n( : )\\"));
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(22221111)) == nospaces(" ___ \n .....\n(o.o)\n<( : )>\n( : )"));
}

TEST_CASE("Number invalid:Number is too short:Number must contain 8 digits")
{
	CHECK_THROWS(snowman(1234123));
	CHECK_THROWS(snowman(444333));
	//CHECK_THROWS(snowman());
	CHECK_THROWS(snowman(212));
	CHECK_THROWS(snowman(14));
	CHECK_THROWS(snowman(3));
	CHECK_THROWS(snowman(44213));
	CHECK_THROWS(snowman(11342));
}
TEST_CASE("Number invalid:Number is too long:Number must contain 8 digits")
{
	CHECK_THROWS(snowman(124221243));
	CHECK_THROWS(snowman(431334433));
	CHECK_THROWS(snowman(222222222));
	CHECK_THROWS(snowman(1312312312));
	CHECK_THROWS(snowman(142222223));
	CHECK_THROWS(snowman(1443434343));
}
TEST_CASE("Number invalid: wrong input:The digits in the number must be in range 1-4")
{

	CHECK_THROWS(snowman(78954645));
	CHECK_THROWS(snowman(78954651));
	CHECK_THROWS(snowman(54804667));
	CHECK_THROWS(snowman(66415650));
	CHECK_THROWS(snowman(56511650));
}
