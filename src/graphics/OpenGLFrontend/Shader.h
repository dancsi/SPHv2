#pragma once

#include "glad/glad.h"

#include <exception>
#include <string>
#include <fstream>
#include <iostream>

class Shader {
    friend class ShaderProgram;

protected:
    GLuint id;
public:
    Shader(std::string path, GLenum type) {
        std::ifstream file(path, std::ios::binary);
        if (!file.is_open()) {
            throw std::runtime_error("Shader source not found");
        }

        file.seekg(0, std::ios::end);
        int len = file.tellg();
        file.seekg(0, std::ios::beg);
        char **source = new char *[1];
        source[0] = new char[len + 1];
        file.read(source[0], len);
        id = glCreateShader(type);
        glShaderSource(id, 1, (const char **) source, &len);

        glCompileShader(id);
        GLint status;
        glGetShaderiv(id, GL_COMPILE_STATUS, &status);
        if (status != GL_TRUE) {
            char buf[1024];
            glGetShaderInfoLog(id, 1024, nullptr, buf);
            std::cerr << "Error while compiling shader " << path << std::endl << buf << std::endl;
            throw std::runtime_error(buf);
        }
    }
};