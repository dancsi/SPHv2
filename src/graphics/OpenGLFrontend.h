#pragma once

#include "GraphicalFrontend.h"

#include "glad/glad.h"
#include <GLFW/glfw3.h>

class OpenGLFrontend : public GraphicalFrontend
{
public:
    OpenGLFrontend(SimulationParameters& parameters);
    ~OpenGLFrontend();
    void display(Simulation& simulation);
    bool should_exit();
private:
    GLFWwindow *window;
    void create_window();
};