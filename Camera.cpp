#include "Camera.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>


Camera::Camera(const glm::vec3 & position_arg, float fov, float aspect, float zNear, float zFar)
{
    perspective = glm::perspective(fov, aspect, zNear, zFar);
    position = position_arg;
    forwardDirection = glm::vec3(0, 0, 1);
    upDirection = glm::vec3(0, 1, 0);
}

glm::mat4 Camera::getViewProjection() const
{
    return perspective * glm::lookAt(position, position + forwardDirection, upDirection);
}