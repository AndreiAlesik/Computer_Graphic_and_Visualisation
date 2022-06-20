#version 330 core

in vec2 TexCoords;
out vec4 fragColor;

uniform sampler2D tex;

void main()
{    
    fragColor = texture(tex, TexCoords);
}  