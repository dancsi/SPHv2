#pragma once

#include "Shader.h"

#include <iostream>
#include <vector>

class ShaderProgram {
private:
    GLuint id;


public:
    ShaderProgram(std::initializer_list<Shader> list) {
        id = glCreateProgram();
        std::vector<Shader> shaders(list.begin(), list.end());

        for(const Shader& sh : shaders) {
            glAttachShader(id, sh.id);
        }

        glBindFragDataLocation(id, 0, "outColor");

        glLinkProgram(id);
        use();

        GLuint vao;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        GLint posAttrib = glGetAttribLocation(id, "position");
        glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(posAttrib);
    }

    void use() {
        glUseProgram(id);
    }

    ~ShaderProgram() {
        // don't destroy the shaders for now
    }
};