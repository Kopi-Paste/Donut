#include <vector>

#include "Mesh.hpp"
#include "Vertex.hpp"
#include <glm/glm.hpp>


Mesh::Mesh(std::vector<Vertex> vertices)
{
    drawCount = vertices.size();

    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);

    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> textureCoords;

    for(size_t i = 0; i < drawCount; ++i)
    {
        positions.push_back(vertices[i].position);
        textureCoords.push_back(vertices[i].textureCoord);
    }

    glGenBuffers(NUM_BUFFERS, vertexArrayBuffers);

    glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_BUFFER]);
    glBufferData(GL_ARRAY_BUFFER, drawCount * sizeof(glm::vec3), std::data(positions), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3 /* vec3 */, GL_FLOAT, GL_FALSE, 0, 0);


    glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[TEXTURE_COORD_BUFFER]);
    glBufferData(GL_ARRAY_BUFFER, drawCount * sizeof(glm::vec2), std::data(textureCoords), GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2 /* vec2 */, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &vertexArrayObject);
}

void Mesh::Draw()
{
    glBindVertexArray(vertexArrayObject);

    glDrawArrays(GL_TRIANGLES, 0, drawCount);

    glBindVertexArray(0);
}

