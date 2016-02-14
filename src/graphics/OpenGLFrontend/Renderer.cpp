#include "graphics/OpenGLFrontend.h"

#include "Shader.h"
#include "ShaderProgram.h"

void OpenGLFrontend::display(Simulation &simulation) {
    glfwPollEvents();

    GLfloat vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    Shader vertexShader("src/graphics/OpenGLFrontend/shaders/simple.vert", GL_VERTEX_SHADER);
    Shader fragmetShader("src/graphics/OpenGLFrontend/shaders/simple.frag", GL_FRAGMENT_SHADER);
    ShaderProgram prog {vertexShader, fragmetShader};

    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Swap the screen buffers
    glfwSwapBuffers(window);
}

