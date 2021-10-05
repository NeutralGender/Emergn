#include <com/emergn/interview/Task3/Chamber.h>

#include <algorithm>
#include <cstdint>
#include <iostream>

#include <com/emergn/interview/Task3/LeftParticle.h>
#include <com/emergn/interview/Task3/MoveDirection.h>
#include <com/emergn/interview/Task3/RightParticle.h>

namespace com::emergn::interview {

namespace {
const char LEFT_PARTICLE{'L'};
const char RIGHT_PARTICLE{'R'};
const char EMPTY{'.'};
const char FILLED_LOCATION{'X'};

const std::uint32_t MAX_PARTICLE_SPEED{10};
const std::size_t MAX_CHAMBER_SIZE{50};

bool checkInitSpeed(int speed)
{
    return ((speed > 0 && static_cast<uint32_t>(speed) <= MAX_PARTICLE_SPEED) ? true : false);
}

bool checkInitChamberCondition(const std::string& chamberInitCondition)
{
    return ((chamberInitCondition.size() > 0 && chamberInitCondition.size() <= MAX_CHAMBER_SIZE)
                ? true
                : false);
}

bool checkInitConditions(int speed, const std::string& chamberInitCondition)
{
    return ((checkInitSpeed(speed)) && checkInitChamberCondition(chamberInitCondition));
}

std::string createInitStateString(const std::string& chamberInitCondition)
{
    std::string initState(chamberInitCondition.size(), EMPTY);
    for (const auto& character : chamberInitCondition) {
        if (character != EMPTY) {
            initState[&character - &chamberInitCondition[0]] = FILLED_LOCATION;
        }
    }

    return initState;
}

}  // namespace

std::vector<std::string> Chamber::animate(int speed, const std::string& chamberInitCondition)
{
    if (not checkInitConditions(speed, chamberInitCondition)) {
        return {};
    }

    std::vector<std::string> chamberStates;
    chamberStates.reserve((chamberInitCondition.size() / static_cast<std::size_t>(speed)));
    chamberStates.push_back(createInitStateString(chamberInitCondition));

    parseInitState(speed, chamberInitCondition);
    uint8_t particleCount = std::count_if(mLinearContainer.begin(), mLinearContainer.end(),
                                          [](auto& particle) { return particle != nullptr; });

    while (particleCount > 0) {
        for (auto& particle : mLinearContainer) {
            if (particle) {
                std::int8_t newparticlePosition = particle->move();
                if (static_cast<std::size_t>(newparticlePosition) >= mLinearContainer.size() ||
                    newparticlePosition < 0) {
                    particle.reset(nullptr);
                    --particleCount;
                }
            }
        }

        chamberStates.push_back(drawChamberState());
    }

    return chamberStates;
}

void Chamber::parseInitState(int speed, const std::string& chamberInitCondition)
{
    mLinearContainer.reserve(chamberInitCondition.size());

    for (const auto& particle : chamberInitCondition) {
        switch (particle) {
        case LEFT_PARTICLE: {
            std::unique_ptr<Particle> leftParticle = std::make_unique<LeftParticle>(
                static_cast<uint8_t>(speed), &particle - &chamberInitCondition[0]);
            mLinearContainer.push_back(std::move(leftParticle));
            break;
        }
        case RIGHT_PARTICLE: {
            std::unique_ptr<Particle> rightParticle = std::make_unique<RightParticle>(
                static_cast<uint8_t>(speed), &particle - &chamberInitCondition[0]);
            mLinearContainer.push_back(std::move(rightParticle));
            break;
        }
        default: {
            mLinearContainer.push_back(nullptr);
            break;
        }
        }
    }
}

std::string Chamber::drawChamberState()
{
    std::string chamberState(mLinearContainer.size(), EMPTY);
    for (const auto& particle : mLinearContainer) {
        if (particle) {
            chamberState[particle->getCurrentLocation()] = FILLED_LOCATION;
        }
    }

    return chamberState;
}

}  // namespace com::emergn::interview
