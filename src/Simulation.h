#pragma once

#include "Particle.h"
#include "SimulationParameters.h"

#include <vector>

class Simulation
{
private:
    friend class Frontend;
public:
    std::vector<Particle> pos;

    Simulation(SimulationParameters &parameters);

    void step(float dt);

};