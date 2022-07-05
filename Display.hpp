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
        void Clear(float r, float g, float b, float a);

        const int width;
        const int height;        

    private:
        SDL_Window * window;
        SDL_GLContext context;
};