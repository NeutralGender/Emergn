#pragma once

#include <cstdint>

#include <com/emergn/interview/Task3/MoveDirection.h>

namespace com::emergn::interview {

class Particle {
public:
    Particle(MoveDirection moveDirection,
             const std::uint8_t speed,
             const std::int8_t currentLocation);
    virtual ~Particle() = default;

    MoveDirection getMoveDirection() const;

    std::int8_t getCurrentLocation() const;

    virtual int8_t move() = 0;

protected:
    MoveDirection mMoveDirection;
    std::uint8_t mSpeed{0};
    std::int8_t mCurrentLocation{0};
};

}  // namespace com::emergn::interview
