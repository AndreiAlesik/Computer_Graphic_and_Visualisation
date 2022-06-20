#version 330 core

out vec4 fragColor;

in vec3 Normal;
in vec3 Position;

uniform vec3 cameraPosition;
uniform samplerCube skybox;

void main()
{
	vec3 I = normalize(Position - cameraPosition);
    vec3 R = reflect(I, normalize(Normal));
    R.y = -R.y;
    fragColor = vec4(texture(skybox, R).rgb, 0.7f);
}