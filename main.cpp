#include <iostream>
#include "core/vector.h"
#include <SDL2/SDL.h>

int main(int argc, char* argv[]) 
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) 
    {
        std::cout << "SDL Failed to initialize: " << SDL_GetError() << std::endl;
        return 1;
    }

    // 2. Create the Window
    SDL_Window* window = SDL_CreateWindow(
        "My First SDL2 Window",      // Window title
        SDL_WINDOWPOS_CENTERED,      // X position
        SDL_WINDOWPOS_CENTERED,      // Y position
        800,                         // Width
        600,                         // Height
        SDL_WINDOW_SHOWN             // Flags
    );

    if (window == nullptr) 
    {
        std::cout << "Window could not be created: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    bool isRunning = true;
    SDL_Event event;

    while (isRunning) 
    {
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
            {
                isRunning = false;
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}