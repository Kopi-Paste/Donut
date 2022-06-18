#include <iostream>
#include <GL/glew.h>

#include "Display.hpp"
#include "Shader.hpp"

int main()
{
    Display mainScreen(800, 600, "Donut");

    Shader shader("./basicshader");

    while (!mainScreen.isClosed)
    {
        glClearColor(0.32f, 0.15f, 0.21f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Bind();

        mainScreen.Update();
    }

    return 0;
}