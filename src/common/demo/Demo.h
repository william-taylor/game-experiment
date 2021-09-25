
#ifndef _DEMO_H
#define _DEMO_H

#include <functional>

class GLFWwindow;

/*! @brief Container struct for all parameters required for the Demo constructor
 *
 * Uses spdlog under the hood, but might explore other loggers
 * as a later date, so this simple facade helps bring all logging
 * into one class so the under lying implementation can be swapped
 * out easier in future if needed.
 */
struct DemoParams
{
    const char* name;
    int argc;
    const char** argv;
    std::function<void()> load;
    std::function<void()> render;
};

/*! @brief Logging facade for future proofing
 *
 * Uses spdlog under the hood, but might explore other loggers
 * as a later date, so this simple facade helps bring all logging
 * into one class so the under lying implementation can be swapped
 * out easier in future if needed.
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
