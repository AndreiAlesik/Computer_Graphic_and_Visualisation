#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 2) in vec2 texCoords;

out vec2 TexCoords;

uniform mat4 model;
uniform mat4 proj;

void main()
{
    TexCoords = texCoords;
    gl_Position = proj * model * vec4(aPos, 1.0);
}