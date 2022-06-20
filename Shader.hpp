#pragma once

#include <string>

#include <GL/glew.h>

#include "Transform.hpp"


class Shader
{
    public:

    Shader(const std::string & filename);
    ~Shader();
    Shader(const Shader &) = delete;
    const Shader & operator =(const Shader & other) = delete;

    void Bind();

    void Update(const Transform & transform);

    private:

    static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string & errorMessage);
    static GLuint createShader(const std::string & text, GLenum shaderType);
    

    static const int numShaders = 2;


    enum Uniforms
    {
        TRANSFORM_UNIFORM,
        NUM_UNIFORMS
    };

    GLuint program;
    GLuint shaders[numShaders];
    GLuint uniforms[NUM_UNIFORMS];
};