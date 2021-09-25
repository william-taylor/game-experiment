
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

const auto OPENGL_VERSION_MAJOR = 4;
const auto OPENGL_VERSION_MINOR = 0;

int main(int argc, const char* argv[])
{
    const auto glfwInitStatus = glfwInit();

    if (!glfwInitStatus)
    {
        std::cout << "GLFW failed to initialise: " << glfwInitStatus << std::endl;
        return EXIT_FAILURE;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_VERSION_MAJOR);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_VERSION_MINOR);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    const auto window = glfwCreateWindow(720, 480, "Window Title", nullptr, nullptr);

    if (window == nullptr)
    {
        std::cout << "Failed to create window with OpenGL context" << std::endl;
        return EXIT_FAILURE;
    }

    const auto glewInitStatus = glewInit();

    if (!glewInitStatus)
    {
        std::cout << "GLEW failed to initialise: " << std::endl;
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    const auto renderer = glGetString (GL_RENDERER);
    const auto version = glGetString (GL_VERSION);

    std::cout << "OpenGL renderer: " << renderer << std::endl;
    std::cout << "OpenGL version: " << version << std::endl;

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}
