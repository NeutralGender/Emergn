#include <com/emergn/interview/Task3/RightParticle.h>

namespace com::emergn::interview {

RightParticle::RightParticle(const std::uint8_t speed, const std::int8_t currentLocation) :
    Particle(MoveDirection::RIGHT, speed, currentLocation)
{
}

std::int8_t RightParticle::move()
{
    mCurrentLocation = (mCurrentLocation + static_cast<int8_t>(mSpeed));
    return mCurrentLocation;
}

}  // namespace com::emergn::interview
