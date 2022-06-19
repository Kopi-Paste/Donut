#pragma once

#include <vector>

#include <GL/glew.h>

#include "Vertex.hpp"


class Mesh
{
    public:

    Mesh(std::vector<Vertex> vertices);
    ~Mesh();

    Mesh(const Mesh &) = delete;
    const Mesh & operator = (const Mesh & other) = delete;

    void Draw();

    private:

    enum 
    {
        POSITION_BUFFER,
        NUM_BUFFERS
    };

    GLuint vertexArrayObject;
    GLuint vertexArrayBuffers[NUM_BUFFERS];
    size_t drawCount;
};