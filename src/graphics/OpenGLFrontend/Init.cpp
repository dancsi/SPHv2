#include "graphics/OpenGLFrontend.h"

#include <exception>
#include <iostream>

OpenGLFrontend::OpenGLFrontend(SimulationParameters& parameters) : GraphicalFrontend(parameters) {

    glfwSetErrorCallback([](int error, const char *description) {
        std::cerr << description << std::endl;
    });

    if (!glfwInit()) {
        std::exit(EXIT_FAILURE);
    }

    create_window();

    glfwSetKeyCallback(window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);
    });

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cerr << "GLAD: Failed to initialize OpenGL context" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

void OpenGLFrontend::create_window() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(width, height, "SPHv2", nullptr, nullptr);
    if (window == nullptr) {
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
}

bool OpenGLFrontend::should_exit() {
    return glfwWindowShouldClose(window);
}

OpenGLFrontend::~OpenGLFrontend() {
    glfwTerminate();
}

