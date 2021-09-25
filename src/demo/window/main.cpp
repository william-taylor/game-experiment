
#include "../../common/demo/Demo.h"

void load()
{
    // TODO: Load assets (will be passed toolbox)
}

void render()
{
    // TODO: Render scene (will be passed toolbox)
}

int main(int argc, const char* argv[])
{
    Demo demo({ "Window", argc, argv, render, load });
    demo.initialise();
    return demo.run();
}
