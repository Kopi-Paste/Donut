#pragma once

#include <glm/glm.hpp>


struct Vertex
{
    glm::vec3 position;
    glm::vec2 textureCoord;

    Vertex(const glm::vec3 & position_arg, const glm::vec2 & textureCoord_arg);
};