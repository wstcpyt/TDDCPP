#include <gmock/gmock.h>
using namespace testing;

#include "SoundexCore/Soundex.h"

class SoundexEnxoding: public testing::Test{
public:
    Soundex soundex;
};


TEST_F(SoundexEnxoding, RetainsSoleLetterOfOneLetterWord)
{
    ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEnxoding, PadsWithZerosToEnsureThreeDigits)
{
    ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEnxoding, ReplacesConsonantsWithAppropriateDigits){
    EXPECT_THAT(soundex.encode("Ab"), Eq("A100"));
    EXPECT_THAT(soundex.encode("Ac"), Eq("A200"));
    EXPECT_THAT(soundex.encode("Ad"), Eq("A300"));
}