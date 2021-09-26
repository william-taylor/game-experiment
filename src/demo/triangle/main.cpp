
#include "../../common/demo/Demo.h"
#include "../../common/logger/Log.h"
#include <iostream>
#include <fstream>
#include <sstream>

unsigned int vertexArrayObject;
unsigned int vertexBufferObject;
unsigned int shaderProgram;

std::string read(const char* filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        Log::error("Failed to open {}", filename);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void load(/* Toolbox& toolbox */)
{
    const auto vertexShaderSource = read("shaders/vertex.glsl");
    const auto vertexShaderSourceStr = vertexShaderSource.c_str();
    const auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSourceStr, NULL);
    glCompileShader(vertexShader);

    const auto fragmentShaderSource = read("shaders/fragment.glsl");
    const auto fragmentShaderSourceStr = fragmentShaderSource.c_str();
    const auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSourceStr, NULL);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    glGenVertexArrays(1, &vertexArrayObject);
    glGenBuffers(1, &vertexBufferObject);

    glBindVertexArray(vertexArrayObject);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void render(/* Toolbox& toolbox */)
{
    glUseProgram(shaderProgram);
    glBindVertexArray(vertexArrayObject);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void unload(/* Toolbox& toolbox */)
{
    glDeleteVertexArrays(1, &vertexArrayObject);
    glDeleteBuffers(1, &vertexArrayObject);
    glDeleteProgram(shaderProgram);
}


int main(int argc, const char* argv[])
{
    Demo demo({ "Triangle", argc, argv, load, render, unload });
    demo.initialise();
    return demo.run();
}
