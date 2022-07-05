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


bool handleControls(Transform & transform, const Uint8 * keyboardState)
{
    if(keyboardState[SDL_SCANCODE_KP_PLUS])
        transform.position.z -= 0.01;
    if(keyboardState[SDL_SCANCODE_KP_MINUS])
        transform.position.z += 0.01;
    if(keyboardState[SDL_SCANCODE_A])
        transform.position.x -= 0.01;
    if(keyboardState[SDL_SCANCODE_D])
        transform.position.x += 0.01;
    if(keyboardState[SDL_SCANCODE_W])
        transform.position.y -= 0.01;
    if(keyboardState[SDL_SCANCODE_S])
        transform.position.y += 0.01;
    if(keyboardState[SDL_SCANCODE_Q])
        transform.rotation.y += 50;
    if(keyboardState[SDL_SCANCODE_E])
        transform.rotation.y -= 50;
    if(keyboardState[SDL_SCANCODE_I])
        transform.rotation.x += 50;
    if(keyboardState[SDL_SCANCODE_K])
        transform.rotation.x -= 50;
    if(keyboardState[SDL_SCANCODE_J])
        transform.rotation.z += 50;
    if(keyboardState[SDL_SCANCODE_L])
        transform.rotation.z -= 50;
    if(keyboardState[SDL_SCANCODE_X])
        return false;
    return true;
}

int main()
{
    Display mainScreen(1240, 1080, "Donut");

    Shader shader("./basicshader");

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

        const Uint8 * state = SDL_GetKeyboardState(nullptr);

        if (!handleControls(transform, state))
            break;
    }

    return 0;
}