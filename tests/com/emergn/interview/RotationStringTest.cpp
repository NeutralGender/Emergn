#include <com/emergn/interview/Tasks.h>

#include <gtest/gtest.h>

#include <string>
#include <utility>

namespace com::emergn::interview {

namespace {

const std::string INPUT_STRING_FOR_INCORRECT_TESTS{"helloworld"};
const std::string INVALID_ROTAION_STRING{"qorldhello"};
const std::string INVALID_ROTAION_STRING_ANOTHER_SIZE{"worldhellos"};
}  // namespace

class RotationStringTest : public ::testing::TestWithParam<std::pair<std::string, std::string>> {
public:
    RotationStringTest() = default;
    ~RotationStringTest() = default;
};

TEST_P(RotationStringTest, isRotationString_ReceivesDefaultCorrectValue_ReturnsTrue)
{
    auto inputPair = GetParam();

    EXPECT_EQ(true, isRotationString(inputPair.first, inputPair.second));
}

TEST(RotationStringTest, isRotationString_ReceivesInvalidRotationString_ReturnsFalse)
{
    EXPECT_EQ(false, isRotationString(INPUT_STRING_FOR_INCORRECT_TESTS, INVALID_ROTAION_STRING));
}

INSTANTIATE_TEST_CASE_P(RotationStringTests,
                        RotationStringTest,
                        ::testing::Values(std::pair("helloworld", "elloworldh"),
                                          std::pair("helloworld", "lloworldhe"),
                                          std::pair("helloworld", "loworldhel"),
                                          std::pair("helloworld", "oworldhell"),
                                          std::pair("helloworld", "worldhello")));

}  // namespace com::emergn::interview
