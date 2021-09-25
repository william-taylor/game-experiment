
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../logger/Log.h"
#include "Demo.h"

Demo::Demo(DemoParams demoParams) :
        name(demoParams.name),
        render(demoParams.render),
        load(demoParams.load)
{
    Log::info("Starting {} demo", name);
}

Demo::~Demo()
{
    Log::info("Finished {} demo", name);
}

void Demo::initialise()
{
    if (exitEarly)
    {
        Log::info("Skipping initialisation, exit early flag was set");
        return;
    }

    initialiseGLFW();
    initialiseGLEW();

    // NOTE: For loading assets in demo
    load();
}

int Demo::run()
{
    if (!exitEarly)
    {
        while (!glfwWindowShouldClose(window))
        {
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // NOTE: For rendering custom scene
            render();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

    }

    glfwTerminate();

    return exitEarly ? EXIT_FAILURE : EXIT_SUCCESS;
}

void Demo::initialiseGLFW()
{
    if (exitEarly)
    {
        Log::info("Skipping GLFW initialisation, exit early flag was set");
        return;
    }

    const auto glfwInitStatus = glfwInit();

    if (!glfwInitStatus)
    {
        Log::error("GLFW failed to initialise: {}", glfwInitStatus);
        exitEarly = true;
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(720, 480, name, nullptr, nullptr);

    if (window == nullptr)
    {
        Log::error("Failed to create window with OpenGL context");
        exitEarly = true;
        return;
    }

    Log::info("Initialised GLFW successfully");
}

void Demo::initialiseGLEW()
{
    if (exitEarly)
    {
        Log::info("Skipping GLEW initialisation, exit early flag was set");
        return;
    }

    const auto glewInitStatus = glewInit();

    if (!glewInitStatus)
    {
        Log::error("GLEW failed to initialise : {}", glewInitStatus);
        exitEarly = true;
        return;
    }

    glfwMakeContextCurrent(window);

    const auto renderer = glGetString(GL_RENDERER);
    const auto version = glGetString(GL_VERSION);

    Log::info("OpenGL renderer: {}", renderer);
    Log::info("OpenGL version: {}", version);
}
