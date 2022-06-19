#include <vector>

#include "Mesh.hpp"
#include "Vertex.hpp"


Mesh::Mesh(std::vector<Vertex> vertices)
{
    drawCount = vertices.size();

    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);

    glGenBuffers(NUM_BUFFERS, vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_BUFFER]);
    glBufferData(GL_ARRAY_BUFFER, drawCount * sizeof(Vertex), std::data(vertices), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3 /* vec3 */, GL_FLOAT, GL_FALSE, 0, 0);

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

