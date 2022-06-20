#ifndef SMOKE_H
#define SMOKE_H

#include"glad/glad.h"
#include"shaderProgram.h"
#include"camera.h"
#include"texture.h"
#include"VBO.h"
#include"VAO.h"
#include<vector>
#include<string>

class Smoke
{
	private:
		Texture *texture;
		std::string textureFile = "textures/smoke/smoke.jpg";
		VAO _VAO;
		std::vector<Vertex> smokeVertices
		{
			// coords							// dummy normals		     // texCoords
			Vertex{glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f)},
			Vertex{glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f)},
			Vertex{glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},

			Vertex{glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f)},
			Vertex{glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
			Vertex{glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f)}
		};
	public:
		Smoke();
		void Draw(ShaderProgram& shader, Camera& camera);
};

#endif // !SMOKE_H