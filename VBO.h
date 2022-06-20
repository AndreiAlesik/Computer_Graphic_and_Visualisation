#ifndef VBO_H
#define VBO_H

#include<glm/glm.hpp>
#include<glad/glad.h>
#include<vector>

struct Vertex
{
	glm::vec3 coords;
	glm::vec3 normal;
	glm::vec2 texCoords;
};

class VBO
{
	public:
		GLuint ID;
		VBO(std::vector<Vertex> vertices);
		void Bind();
		void Unbind();
		void Delete();
};

#endif // !VBO_H
