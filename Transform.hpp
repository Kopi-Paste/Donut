#pragma once

#include <glm/glm.hpp>

struct Transform
{
    public:
    Transform(const glm::vec3 & position_arg = glm::vec3(0.0f, 0.0f, 0.0f), const glm::vec3 & rotation_arg = glm::vec3(0.0f, 0.0f, 0.0f), const glm::vec3 & scale_arg = glm::vec3(1.0f, 1.0f, 1.0f));

    glm::mat4 getModel() const;

    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};