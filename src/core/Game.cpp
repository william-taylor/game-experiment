
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <yaml-cpp/yaml.h>
#include <docopt/docopt.h>
#include <string>
#include "Game.h"

void start_game(std::string manifest_path)
{
    auto window_config = YAML::LoadFile(manifest_path)["window"];
    auto title = window_config["title"].as<std::string>();
    auto width = window_config["width"].as<int>();
    auto height = window_config["height"].as<int>();

    glfwInit();
    glewInit();

    auto window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f,0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}
