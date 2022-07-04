#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Display.hpp"
#include "Shader.hpp"
#include "Mesh.hpp"
#include "Vertex.hpp"
#include "Texture.hpp"
#include "Transform.hpp"
#include "Camera.hpp"
#include "Statics.hpp"

int main()
{
    Display mainScreen(1240, 1080, "Donut");

    Shader shader("./basicshader");

    std::vector<Vertex> vertices = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)), Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)), Vertex(glm::vec3(-0.5, 0.5, 0), glm::vec2(1.0, 0.0))};

    std::vector<unsigned int> indicies = { 0, 1, 2};

    Mesh dough("dough.obj");

    Mesh icing("icing.obj");

    Texture doughT("dough-texture.jpg");

    Texture icingT("icing-texture.jpg");

    Transform transform;

    Camera camera(glm::vec3(0, 0, -0.3f), 70.0f, (float)mainScreen.width / (float)mainScreen.height, 0.01f, 1000.0f);

    while (!mainScreen.isClosed)
    {
        mainScreen.Clear(0.32f, 0.15f, 0.21f, 1.0f);

        shader.Bind();
        shader.Update(transform, camera);

        doughT.Bind(0);

        dough.Draw();

        icingT.Bind(0);

        icing.Draw();

        mainScreen.Update();

        char c = getChar();

        switch (c)
        {
        case '+':
            transform.position.z -= 0.01;
            break;

        case '-':
            transform.position.z += 0.01;
            break;

        case 'a':
            transform.position.x -= 0.01;
            break;

        case 'd':
            transform.position.x += 0.01;
            break;

        case 'w':
            transform.position.y -= 0.01;
            break;

        case 's':
            transform.position.y += 0.01;
            break;

        case 'q':
            transform.rotation.y += 50;
            break;
        
        case 'e':
            transform.rotation.y -= 50;
            break;

        case 'i':
            transform.rotation.x += 50;
            break;

        case 'k':
            transform.rotation.x -= 50;
            break;

        case 'j':
            transform.rotation.z += 50;
            break;

        case 'l':
            transform.rotation.z -= 50; 
            break;

        case 'x':
            return 0;

        default:
            break;
        }
    }

    return 0;
}