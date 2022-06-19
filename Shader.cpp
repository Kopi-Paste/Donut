#include <string>
#include <iostream>

#include "Shader.hpp"
#include "Statics.hpp"

Shader::Shader(const std::string & filename)
{
    program = glCreateProgram();
    shaders[0] = createShader(readFile(filename + ".vs"), GL_VERTEX_SHADER);
    shaders[1] = createShader(readFile(filename + ".fs"), GL_FRAGMENT_SHADER);

    for (int i = 0; i < numShaders; ++i)
        glAttachShader(program, shaders[i]);
    
    glBindAttribLocation(program, 0, "position");
    glBindAttribLocation(program, 1, "textureCoord");

    glLinkProgram(program);
    checkShaderError(program, GL_LINK_STATUS, true, "Program Linking Failed");

    glValidateProgram(program);
    checkShaderError(program, GL_VALIDATE_STATUS, true, "Program is invalid");
}

Shader::~Shader()
{
    for (int i = 0; i < numShaders; ++i)
    {
        glDetachShader(program, shaders[i]);
        glDeleteShader(shaders[i]);
    }
    glDeleteProgram(program);
}

void Shader::Bind()
{
    glUseProgram(program);
}

void Shader::checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string & errorMessage)
{
    static const int messageLength = 1024;

    GLint code = GL_FALSE;

    GLchar error[messageLength] = { 0 };

    auto ivFunc = isProgram ? glGetProgramiv : glGetShaderiv;
    ivFunc(shader, flag, &code);

    if (code == GL_FALSE)
    {
        auto infoLogFunc = isProgram ? glGetProgramInfoLog : glGetShaderInfoLog;
        infoLogFunc(shader, sizeof(error), nullptr, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}

GLuint Shader::createShader(const std::string & text, GLenum shaderType)
{
    static const int sources = 1;

    GLuint shader = glCreateShader(shaderType);
    if (!shader)
        throw std::invalid_argument(std::string("Shader could not be created"));
    const GLchar * shaderSources[sources];
    GLint shaderSourcesLengths[sources];

    shaderSources[0] = text.c_str();
    shaderSourcesLengths[0] = text.length();

    glShaderSource(shader, sources, shaderSources, shaderSourcesLengths);
    glCompileShader(shader);

    checkShaderError(shader, GL_COMPILE_STATUS, false, "Error compiling shader");

    return shader;
}