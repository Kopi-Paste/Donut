#pragma once

#include <vector>

#include <GL/glew.h>

#include "obj_loader.hpp"
#include "Vertex.hpp"


class Mesh
{
    public:

    Mesh(const std::vector<Vertex> & vertices, const std::vector<unsigned int> & indicies);
    Mesh(const std::string & fileName);
    ~Mesh();

    Mesh(const Mesh &) = delete;
    const Mesh & operator = (const Mesh & other) = delete;

    void Draw();

    private:

    enum 
    {
        POSITION_BUFFER,
        TEXTURE_COORD_BUFFER,
        INDEX_BUFFER,
        NUM_BUFFERS
    };

    GLuint vertexArrayObject;
    GLuint vertexArrayBuffers[NUM_BUFFERS];
    size_t drawCount;
};