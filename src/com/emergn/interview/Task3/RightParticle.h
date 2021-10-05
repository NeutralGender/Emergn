#pragma once

#include <cstdint>

#include <com/emergn/interview/Task3/MoveDirection.h>
#include <com/emergn/interview/Task3/Particle.h>

namespace com::emergn::interview {

class RightParticle : public Particle {
public:
    RightParticle(const std::uint8_t speed, const std::int8_t currentLocation);
    virtual ~RightParticle() = default;

    virtual std::int8_t move() override;
};

}  // namespace com::emergn::interview
