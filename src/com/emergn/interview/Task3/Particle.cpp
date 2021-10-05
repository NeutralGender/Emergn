#include <com/emergn/interview/Task3/Particle.h>

namespace com::emergn::interview {

Particle::Particle(MoveDirection moveDirection,
                   const std::uint8_t speed,
                   const std::int8_t currentLocation) :
    mMoveDirection(moveDirection),
    mSpeed(speed), mCurrentLocation(currentLocation)
{
}

MoveDirection Particle::getMoveDirection() const
{
    return mMoveDirection;
}

std::int8_t Particle::getCurrentLocation() const
{
    return mCurrentLocation;
}

}  // namespace com::emergn::interview
