#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include "Transform.hpp"

Transform::Transform(const glm::vec3 & position_arg, const glm::vec3 & rotation_arg, const glm::vec3 & scale_arg) : position(position_arg), rotation(rotation_arg), scale(scale_arg)
{}

glm::mat4 Transform::getModel() const
{
    glm::mat4 positionMatrix = glm::translate(position);

    glm::mat4 rotationXMatrix = glm::rotate(rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 rotationYMatrix = glm::rotate(rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 rotationZMatrix = glm::rotate(rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4 rotationMatrix = rotationZMatrix * rotationYMatrix * rotationXMatrix;

    glm::mat4 scaleMatrix = glm::scale(scale);

    return positionMatrix * rotationMatrix * scaleMatrix;
}