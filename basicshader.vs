#version 120

attribute vec3 position;
attribute vec2 textureCoord;

varying vec2 textureCoordVarying;

uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(position, 1.0);
    textureCoordVarying = textureCoord;
}
