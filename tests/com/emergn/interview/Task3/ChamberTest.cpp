#include <com/emergn/interview/Task3/Chamber.h>

#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

namespace com::emergn::interview {

namespace {
const int INVALID_SPEED_BELOW_ZERO{-1};
const int INVALID_SPEED_ABOVE_MAX{11};

// 51 charecter
const std::string INVALID_CHAMBER_INIT_STATE{"..................................................."};

}  // namespace

class ChamberTest :
    public ::testing::TestWithParam<
        std::pair<std::pair<int, std::string>, std::vector<std::string>>> {
public:
    ChamberTest() = default;
    ~ChamberTest() = default;

protected:
    Chamber mChamber;
};

TEST_P(ChamberTest, animate_ReceivesDefaultCorrectInputState_ReturnsDefaultsValues)
{
    auto inputValues = GetParam();

    auto testedResult = mChamber.animate(inputValues.first.first, inputValues.first.second);
    EXPECT_EQ(inputValues.second, testedResult);
}

TEST_P(ChamberTest, animate_ReceivesInvalidSpeedBelowZeroValue_ReturnsEmptyVector)
{
    auto inputValues = GetParam();

    auto testedResult = mChamber.animate(INVALID_SPEED_BELOW_ZERO, inputValues.first.second);
    EXPECT_EQ(std::vector<std::string>{}, testedResult);
}

TEST_P(ChamberTest, animate_ReceivesInvalidSpeedAboveMaxValue_ReturnsEmptyVector)
{
    auto inputValues = GetParam();

    auto testedResult = mChamber.animate(INVALID_SPEED_ABOVE_MAX, inputValues.first.second);
    EXPECT_EQ(std::vector<std::string>{}, testedResult);
}

TEST_P(ChamberTest, animate_ReceivesInvalidChamberInitState_ReturnsEmptyVector)
{
    auto inputValues = GetParam();

    auto testedResult = mChamber.animate(inputValues.first.first, INVALID_CHAMBER_INIT_STATE);
    EXPECT_EQ(std::vector<std::string>{}, testedResult);
}

INSTANTIATE_TEST_CASE_P(
    ChamberTests,
    ChamberTest,
    ::testing::Values(
        std::pair(std::pair(2, "..R...."),
                  std::vector<std::string>{std::string("..X...."), std::string("....X.."),
                                           std::string("......X"), std::string(".......")}),
        std::pair(std::pair(3, "RR..LRL"),
                  std::vector<std::string>{std::string("XX..XXX"), std::string(".X.XX.."),
                                           std::string("X.....X"), std::string(".......")}),
        std::pair(std::pair(2, "LRLR.LRLR"),
                  std::vector<std::string>{std::string("XXXX.XXXX"), std::string("X..X.X..X"),
                                           std::string(".X.X.X.X."), std::string(".X.....X."),
                                           std::string(".........")}),
        std::pair(std::pair(10, "RLRLRLRLRL"),
                  std::vector<std::string>{std::string("XXXXXXXXXX"), std::string("..........")}),
        std::pair(std::pair(1, "..."), std::vector<std::string>{std::string("...")})));

}  // namespace com::emergn::interview
