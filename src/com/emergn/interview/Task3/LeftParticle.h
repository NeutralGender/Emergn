#pragma once

#include <cstdint>

#include <com/emergn/interview/Task3/MoveDirection.h>
#include <com/emergn/interview/Task3/Particle.h>

namespace com::emergn::interview {

class LeftParticle : public Particle {
public:
    LeftParticle(const std::uint8_t speed, const std::int8_t currentLocation);
    virtual ~LeftParticle() = default;

    virtual std::int8_t move() override;
};

}  // namespace com::emergn::interview
