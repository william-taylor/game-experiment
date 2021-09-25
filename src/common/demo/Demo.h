
#ifndef _DEMO_H
#define _DEMO_H

#include <functional>

class GLFWwindow;

/*!
 * @brief Data class params required for the demo class
 */
struct DemoParams
{
    const char* name;
    int argc;
    const char** argv;
    std::function<void()> load;
    std::function<void()> render;
};

/*!
 * @brief Bootstraps an OpenGL environment for a demo
 */
class Demo
{
private:
    const char* name;
    GLFWwindow* window;
    bool exitEarly;
    std::function<void()> load;
    std::function<void()> render;
public:
    Demo(DemoParams demoParams);
    Demo(const Demo& demo) = delete;
    Demo(Demo&& demo) = delete;
    ~Demo();

    Demo& operator=(const Demo& demo) = delete;

    void initialise();
    int run();
private:

    void initialiseGLFW();
    void initialiseGLEW();
};


#endif
