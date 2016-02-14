#pragma once

#include "Simulation.h"
#include "SimulationParameters.h"

class Frontend
{
public:
    Frontend(SimulationParameters& parameters) {}

    virtual void display (Simulation& simulation) = 0;
};