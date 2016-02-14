#pragma once

#include <boost/filesystem/path.hpp>
#include <boost/program_options.hpp>

class SimulationParameters
{
private:
    boost::program_options::options_description optionsDescription;
    boost::program_options::variables_map vm;

public:
    SimulationParameters ();

    template <typename T>
    T get(std::string property) {
        return vm[property].as<T>();
    }

    void loadDefault();
    void loadFromFile(boost::filesystem::path path);
    void loadCommandLine(int argc, char** argv);
};