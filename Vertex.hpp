#pragma once

#include <glm/glm.hpp>


struct Vertex
{
    glm::vec3 position;

    Vertex(const glm::vec3 & position_arg);
};