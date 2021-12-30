#include <iostream>
#include <math.h>
#include "Application.h"

int main(int argc, char* args[])
{
    Application app;

    app.Setup();

    while (app.IsRunning())
    {
        Uint64 startTime = SDL_GetPerformanceCounter();

        app.Input();
        app.Update();
        app.Render();

        Uint64 endTime = SDL_GetPerformanceCounter();
        float elapsedTime = (endTime - startTime) / (float)SDL_GetPerformanceFrequency() * 1000.0f;

        // Cap to 30 FPS
        float delay = floor(33.333f - elapsedTime);
        if (delay > 0)
        {
            SDL_Delay(delay);
        }
    }

    app.Destroy();

    return 0;
}

