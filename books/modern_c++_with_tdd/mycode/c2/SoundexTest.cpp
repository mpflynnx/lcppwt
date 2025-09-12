#include <string>

class Soundex {

public:
  std::string encode(const std::string &word) const { return word + "000"; }
};

#include "gmock/gmock.h"
using ::testing::Eq;

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
  Soundex soundex;

  auto encoded = soundex.encode("C");

  EXPECT_THAT(encoded, Eq("C000"));
}

TEST(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
  Soundex soundex;

  auto encoded = soundex.encode("I");

  EXPECT_THAT(encoded, Eq("I000"));
}
