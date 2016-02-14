#include <iostream>

#include "Simulation.h"
#include "graphics/OpenGLFrontend.h"
#include "SimulationParameters.h"

using namespace std;

int main(int argc, char **argv)
{
    SimulationParameters params;
    params.loadDefault();
    params.loadCommandLine(argc, argv);

    Simulation simulation(params);
    OpenGLFrontend glFrontend(params);

    while(!glFrontend.should_exit())
    {
        simulation.step(0.1);
        glFrontend.display(simulation);
    }

    return 0;
}