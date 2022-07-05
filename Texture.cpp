#include <string>
#include <stdexcept>

#include "Texture.hpp"
#include "stb_image.hpp"

Texture::Texture(const std::string & filename)
{
    int height, width, numComponents;
    unsigned char * imageData = stbi_load(filename.c_str(), &width, &height, &numComponents, 4);

    if (imageData == nullptr)
        throw std::invalid_argument(std::string("Texture loading failed"));

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

    stbi_image_free(imageData);
}

Texture::~Texture()
{
    glDeleteTextures(1, &texture);
}


void Texture::Bind(int unit)
{
    if (unit < 0 || unit >= 32)
        throw std::invalid_argument(std::string("Unit must be between 0 and 32"));
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, texture);
}