#pragma once

#include <string>
#include <SDL2/SDL.h>

class Display
{
    public:
        bool isClosed;

        Display(int width, int height, const std::string & title);
        ~Display();
        Display(const Display & other) = delete;
        Display & operator =(const Display & other) = delete;

        void Update();

    private:
        SDL_Window * window;
        SDL_GLContext context;

};