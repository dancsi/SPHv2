#include "SimulationParameters.h"

#include <fstream>

using namespace boost::program_options;

SimulationParameters::SimulationParameters() {

    options_description coreOptions("Core");
    options_description constantsOptions("Constants");
    options_description graphicsOptions("Graphics");

    coreOptions.add_options()
            ("numParticles", value<int>()->default_value(1000), "Number of particles to simulate")
            ("timeStep", value<float>()->default_value(0.05), "Simulation time step, in seconds")
            ;

    constantsOptions.add_options()
            ("gravity", value<float>()->default_value(9.81), "Constant downward force")
            ;

    graphicsOptions.add_options()
            ("enableGraphics", value<bool>()->default_value(true))
            ("windowWidth", value<int>()->default_value(640))
            ("windowHeight", value<int>()->default_value(480))
            ;

    optionsDescription
            .add(coreOptions)
            .add(constantsOptions)
            .add(graphicsOptions);
}

void SimulationParameters::loadDefault() {
    loadFromFile("SPH.cfg");
}

void SimulationParameters::loadFromFile(boost::filesystem::path path) {
    std::ifstream file(path.string());
    store(parse_config_file(file, optionsDescription), vm);
}

void SimulationParameters::loadCommandLine(int argc, char **argv) {
    store(parse_command_line(argc, argv, optionsDescription), vm);
}

