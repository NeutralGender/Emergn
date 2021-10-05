#include <cstdint>

#include <com/emergn/interview/Task3/LeftParticle.h>
#include <com/emergn/interview/Task3/MoveDirection.h>

namespace com::emergn::interview {

LeftParticle::LeftParticle(const std::uint8_t speed, const std::int8_t currentLocation) :
    Particle(MoveDirection::LEFT, speed, currentLocation)
{
}

std::int8_t LeftParticle::move()
{
    mCurrentLocation = (mCurrentLocation - static_cast<int8_t>(mSpeed));
    return mCurrentLocation;
}

}  // namespace com::emergn::interview
