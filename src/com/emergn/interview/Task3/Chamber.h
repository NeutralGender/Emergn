#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include <com/emergn/interview/Task3/Particle.h>

namespace com::emergn::interview {

class Chamber {
public:
    Chamber() = default;
    ~Chamber() = default;

    /**
     * @brief Problem3: Animate particles actions in chamber
     *
     * @param speed All particles speed
     * @param chamberInitCondition Chamber initial condition
     */
    std::vector<std::string> animate(int speed, const std::string& chamberInitCondition);

private:
    void parseInitState(int speed, const std::string& chamberInitCondition);
    std::string drawChamberState();

private:
    std::vector<std::unique_ptr<Particle>> mLinearContainer;
};

}  // namespace com::emergn::interview
