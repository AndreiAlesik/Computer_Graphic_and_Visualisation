#version 330 core

out vec4 fragColor;

in vec2 texCoord;
in vec3 Normal;
in vec3 vertexPosition;

uniform sampler2D tex;

uniform vec4 lightColor;
uniform vec3 cameraPosition;

void main()
{
	vec3 directLightDirection = vec3(1.0, -1.0, 0.0);

	// AMBIENT
	float ambient = 0.4;

	// DIFFUSE
	vec3 lightDirection = normalize(directLightDirection);
	float diffuse = max(dot(Normal, lightDirection), 0.0);

	//SPECULAR
	float specularLight = 0.5;
	vec3 viewDirection = normalize(cameraPosition - vertexPosition);
	vec3 reflectionDirection = reflect(-lightDirection, Normal);
	float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0), 8);
	float specular = specAmount * specularLight;

	vec4 retValue = (texture(tex, texCoord) * lightColor * (diffuse + ambient + specular));
	retValue.a = 1.0;

	fragColor = retValue;
}