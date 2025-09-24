#include "Soundex.h"
#include "gmock/gmock.h"

using ::testing::Eq;
using ::testing::Test;

class SoundexEncoding : public Test {
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

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
  auto encoded = soundex.encode("At");

  ASSERT_THAT(encoded, Eq("A300"));
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetical) {
  auto encoded = soundex.encode("A#");

  ASSERT_THAT(encoded, Eq("A000"));
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
  auto encoded = soundex.encode("Acdl");

  ASSERT_THAT(encoded, Eq("A234"));
}

/*
* The return value from soundex.encode() must have length equal to 4
*/
TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
   ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u)); 
}
