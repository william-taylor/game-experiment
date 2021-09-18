#include <SDL.h>
#include <GL/glew.h>

bool process_window_events()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE)
        {
            SDL_Log("Shutting down...");
            return true;
        }
    }

    return false;
}

bool initialise_opengl(SDL_Window *window)
{
    SDL_GLContext context = SDL_GL_CreateContext(window);

    if (context == nullptr)
    {
        SDL_Log("Failed to create GL context in SDL");
        return true;
    }

    GLenum error = glewInit();

    if (error != GLEW_OK)
    {
        SDL_Log("Failed to initialise GLEW() %s", error);
        return true;
    }

    return false;
}

void render_scene()
{
    glClearColor(0.0f, 0.0f, 0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void start_game_loop(SDL_Window* window)
{
    bool shutdown = false;

    while(!shutdown)
    {
        if (process_window_events())
        {
            shutdown = true;
        }

        render_scene();

        SDL_GL_SwapWindow(window);
    }
}

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Title", 100, 100, 720, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    if (initialise_opengl(window))
    {
        SDL_Log("Failed to initialise opengl");
        return 1;
    }

    start_game_loop(window);

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
