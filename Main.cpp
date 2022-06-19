#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Display.hpp"
#include "Shader.hpp"
#include "Mesh.hpp"
#include "Vertex.hpp"

int main()
{
    Display mainScreen(800, 600, "Donut");

    Shader shader("./basicshader");

    std::vector<Vertex> vertices = { Vertex(glm::vec3(-0.5, -0.5, 0)), Vertex(glm::vec3(0, 0.5, 0)), Vertex(glm::vec3(-0.5, 0.5, 0))};

    Mesh mesh(vertices);

    while (!mainScreen.isClosed)
    {
        glClearColor(0.32f, 0.15f, 0.21f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Bind();

        mesh.Draw();

        mainScreen.Update();
    }

    return 0;
}