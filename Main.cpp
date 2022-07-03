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

int main()
{
    Display mainScreen(800, 600, "Donut");

    Shader shader("./basicshader");

    std::vector<Vertex> vertices = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)), Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)), Vertex(glm::vec3(-0.5, 0.5, 0), glm::vec2(1.0, 0.0))};

    std::vector<unsigned int> indicies = { 0, 1, 2};

    Mesh monkey("monkey3.obj");

    Texture texture("bricks.jpg");

    Transform transform;

    Camera camera(glm::vec3(0, 0, -3.0f), 80.0f, (float)mainScreen.width / (float)mainScreen.height, 0.01f, 1000.0f);

    float counter = 0.0f;

    while (!mainScreen.isClosed)
    {
        mainScreen.Clear(0.32f, 0.15f, 0.21f, 1.0f);


        float sinCounter = sinf(counter);
        float cosCounter = cosf(counter);


        transform.position.x = sinCounter / 100;
        transform.position.z = cosCounter / 100;
        transform.rotation.x = counter * 5;
        transform.rotation.y = counter * 5;
        transform.rotation.z = counter * 5;


        shader.Bind();
        shader.Update(transform, camera);

        texture.Bind(0);

        monkey.Draw();

        mainScreen.Update();

        counter += 0.001f;
        if (counter > 100.0f)
            counter = 0.0f;
    }

    return 0;
}