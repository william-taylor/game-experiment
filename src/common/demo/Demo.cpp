
#include "../logger/Log.h"
#include "Demo.h"

Demo::Demo(DemoParams demoParams) :
        name(demoParams.name),
        render(demoParams.render),
        unload(demoParams.unload),
        load(demoParams.load),
        exitEarly(false)
{
    Log::info("Starting {} demo", name);
}

Demo::~Demo()
{
    Log::info("Finished {} demo", name);
}

void Demo::initialise()
{
    initialiseGLFW();
    initialiseGLEW();
}

int Demo::run()
{
    if (!exitEarly)
    {
        load();

        while (!glfwWindowShouldClose(window))
        {
            // TODO: Custom input callback
            if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            {
                Log::info("Escape key pressed, closing window");
                glfwSetWindowShouldClose(window, true);
            }

            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            render();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        unload();
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
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    const auto title = name + " demo";
    Log::info("Window title will be set as: {}", title);
    window = glfwCreateWindow(800, 500, title.c_str(), nullptr, nullptr);

    if (window == nullptr)
    {
        Log::error("Failed to create triangle with OpenGL context");
        exitEarly = true;
        return;
    }

    glfwMakeContextCurrent(window);

    // TODO: Custom resize callback
    glfwSetFramebufferSizeCallback(window, [](auto window, auto width, auto height) {
        glViewport(0, 0, width, height);
    });

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

    if (glewInitStatus != GLEW_OK)
    {
        Log::error("GLEW failed to initialise : {}", glewInitStatus);
        exitEarly = true;
        return;
    }

    const auto renderer = glGetString(GL_RENDERER);
    const auto version = glGetString(GL_VERSION);

    Log::info("OpenGL renderer: {}", renderer);
    Log::info("OpenGL version: {}", version);
}
