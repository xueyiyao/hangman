//test.cpp

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "hangman.h"
#include <fstream>
#include <string>

using namespace std;

// int main(){
// 	hangman h1;
// 	return 0;
// }

TEST_CASE("hangman constructor", "[hangman]") {

	hangman h1;

	REQUIRE(h1.printWord() == "");
	REQUIRE(h1.printFound() == "");
	REQUIRE(h1.printInc() == "");
	REQUIRE((h1.printWord()).length() == 0);
	REQUIRE(h1.displayLives() == 7);

}

TEST_CASE("hangman readWord function", "[hangman]"){

	hangman h2;

	SECTION("reading empty strings"){
		h2.readWord("");

		REQUIRE(h2.printWord() == "");
		REQUIRE(h2.printFound() == "");
		REQUIRE((h2.printWord()).length() == 0);
	}

	SECTION("reading basic lowercase words"){
		h2.readWord("simple");

		REQUIRE(h2.printWord() == "simple");
		REQUIRE(h2.printFound() == "_ _ _ _ _ _");
		REQUIRE((h2.printWord()).length() == 6);
	}

	SECTION("reading words containing lower and upper case letters"){
		h2.readWord("MiXeD");

		REQUIRE(h2.printWord() == "mixed");
		REQUIRE(h2.printFound() == "_ _ _ _ _");
		REQUIRE((h2.printWord()).length() == 5);
	}

	SECTION("reading words containing non alpha characters"){

		SECTION("reading words containing invalid characters"){
			h2.readWord("In. valid!");

			REQUIRE(h2.printWord() == "invalid");
			REQUIRE(h2.printFound() == "_ _ _ _ _ _ _");
			REQUIRE((h2.printWord()).length() == 7);
		}

		 //hypens and apostrophes
		SECTION("reading words contating valid non alpha characters"){
			h2.readWord("baby-shark's");

			REQUIRE(h2.printWord() == "baby-shark's");
			REQUIRE(h2.printFound() == "_ _ _ _ - _ _ _ _ _ ' _");
			REQUIRE((h2.printWord()).length() == 12);
		}
	}

}