#include <iostream>
#include <GL/glew.h>

#include "Display.hpp"

int main()
{
    Display mainScreen(800, 600, "Donut");
    while (!mainScreen.isClosed)
    {
        glClearColor(0.32f, 0.15f, 0.21f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        mainScreen.Update();
    }

    return 0;
}