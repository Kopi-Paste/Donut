#pragma once

#include <string>

#include <GL/glew.h>

class Texture
{
    public:
    Texture(const std::string & filename);
    ~Texture();

    void Bind(int unit);

    Texture(const Texture &) = delete;
    const Texture & operator = (const Texture &) = delete;

    private:
    GLuint texture;
};
