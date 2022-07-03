#include <string>
#include <vector>
#include <iostream>

#include <glm/glm.hpp>

#include "Mesh.hpp"
#include "Vertex.hpp"
#include "obj_loader.hpp"


Mesh::Mesh(const std::vector<Vertex> & vertices, const std::vector<unsigned int> & indicies)
{
    drawCount = indicies.size();

    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);

    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> textureCoords;

    for(const auto & x : vertices)
    {
        positions.push_back(x.position);
        textureCoords.push_back(x.textureCoord);
    }

    glGenBuffers(NUM_BUFFERS, vertexArrayBuffers);

    glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_BUFFER]);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), std::data(positions), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3 /* vec3 */, GL_FLOAT, GL_FALSE, 0, 0);


    glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[TEXTURE_COORD_BUFFER]);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec2), std::data(textureCoords), GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2 /* vec2 */, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexArrayBuffers[INDEX_BUFFER]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size() * sizeof(unsigned int), std::data(indicies), GL_STATIC_DRAW);


    glBindVertexArray(0);
}

Mesh::Mesh(const std::string & fileName)
{
    OBJModel oModel = OBJModel(fileName);

    std::cerr << fileName << " : " << oModel.OBJIndices.size() << std::endl;
    std::cerr << fileName << " : " << oModel.uvs.size() << std::endl;
    std::cerr << fileName << " : " << oModel.vertices.size() << std::endl;
    std::cerr << fileName << " : " << (oModel.hasUVs ? "true" : "false") << std::endl;


    IndexedModel model = oModel.ToIndexedModel();

    drawCount = model.indices.size();

   

    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);

    glGenBuffers(NUM_BUFFERS, vertexArrayBuffers);

    glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_BUFFER]);
    glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(glm::vec3), std::data(model.positions), GL_STATIC_DRAW);    

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3 /* vec3 */, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[TEXTURE_COORD_BUFFER]);
    glBufferData(GL_ARRAY_BUFFER, model.texCoords.size() * sizeof(glm::vec2), std::data(model.texCoords), GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2 /* vec2 */, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexArrayBuffers[INDEX_BUFFER]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size() * sizeof(unsigned int), std::data(model.indices), GL_STATIC_DRAW);


    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &vertexArrayObject);
}

void Mesh::Draw()
{
    glBindVertexArray(vertexArrayObject);

    glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}

