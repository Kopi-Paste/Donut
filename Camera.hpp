#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera
{
    public:
        Camera(const glm::vec3 & position_arg, float fov, float aspect, float zNear, float zFar);
        glm::mat4 getViewProjection() const;
    private:
        glm::mat4 perspective;
        glm::vec3 position;
        glm::vec3 forwardDirection;
        glm::vec3 upDirection;
};