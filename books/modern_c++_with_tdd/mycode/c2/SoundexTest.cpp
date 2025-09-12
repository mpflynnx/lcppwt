#include "Soundex.h"
#include "gmock/gmock.h"

using ::testing::Eq;
using ::testing::Test;

class SoundexEncoding: public Test {
  public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {

  auto encoded = soundex.encode("C");

  EXPECT_THAT(encoded, Eq("C000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {

  auto encoded = soundex.encode("I");

  EXPECT_THAT(encoded, Eq("I000"));
}
