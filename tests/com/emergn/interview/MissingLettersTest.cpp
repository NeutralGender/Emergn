#include <com/emergn/interview/Tasks.h>

#include <gtest/gtest.h>

#include <string>
#include <utility>

namespace com::emergn::interview {

namespace {
const std::string PANGRAM_FOR_INVALID_TESTING{"A quick brown fox jumps over the lazy dog"};
const std::string INVALID_OUTPUT{"ABC"};
}  // namespace

class MissingLettersTest : public ::testing::TestWithParam<std::pair<std::string, std::string>> {
public:
    MissingLettersTest() = default;
    ~MissingLettersTest() = default;
};

TEST_P(MissingLettersTest, getMissingLetters_ReceivesDefaultPangrams_ReturnsExpectedValue)
{
    auto inputPangrams = GetParam();

    EXPECT_EQ(inputPangrams.second, getMissingLetters(inputPangrams.first));
}

TEST(MissingLettersTest, getMissingLetters_ReceivesPangramAndInvalidOutput_NotReturnCorrectOutput)
{
    EXPECT_NE(INVALID_OUTPUT, getMissingLetters(PANGRAM_FOR_INVALID_TESTING));
}

INSTANTIATE_TEST_CASE_P(
    MissingLettersTests,
    MissingLettersTest,
    ::testing::Values(std::pair("A quick brown fox jumps over the lazy dog", ""),
                      std::pair("A uick brown fox jumps over the lazy dog", "Q"),
                      std::pair("A uick bown fox jumps ove the lazy dog", "QR"),
                      std::pair("", "ABCDEFGHIJKLMNOPQRSTUVWXYZ")));

}  // namespace com::emergn::interview
