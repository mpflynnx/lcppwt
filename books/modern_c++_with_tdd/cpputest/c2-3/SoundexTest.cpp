#include <string>

class Soundex {

public:
  std::string encode(const std::string &word) const { return word; }
};

#include "CppUTest/TestHarness.h"

TEST_GROUP(SoundexEncoding) {
};

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
	
	Soundex soundex;
	
	std::string encoded = soundex.encode("C");
	std::string expected = "C";
	
	CHECK_EQUAL(encoded, expected);
}
