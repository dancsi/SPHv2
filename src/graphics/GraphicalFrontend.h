#pragma once

#include "Frontend.h"

class GraphicalFrontend: public Frontend
{
protected:
    int width, height;
public:
    GraphicalFrontend(SimulationParameters& parameters) : Frontend(parameters) {
        width = parameters.get<int>("windowWidth");
        height = parameters.get<int>("windowHeight");
    }
    virtual bool should_exit() = 0;
};