#ifndef MESH_H
#define MESH_H

#include<string>
#include<vector>

#include"EBO.h"
#include"VAO.h"
#include"VBO.h"
#include"camera.h"
#include"texture.h"

class Mesh
{
public:
	std::vector<Vertex> _vertices;
	std::vector<GLuint> _indices;
	std::vector<Texture> _textures;

	glm::mat4 model;

	glm::mat4 rotationMatrix;
	glm::mat4 translationMatrix;
	glm::mat4 scaleMatrix;

	VAO _VAO;

	Mesh(std::vector<Vertex> &vertices, std::vector<GLuint> &indices, std::vector<Texture> &textures);

	void Draw(ShaderProgram &shader, Camera &camera);

	void Rotate(glm::vec3 axis, GLfloat degrees, ShaderProgram& shader);
	void Move(glm::vec3 translation, ShaderProgram& shader);
	void Scale(glm::vec3 scale, ShaderProgram& shader);
	void applyTransformations(ShaderProgram& shader);
};

#endif // !MESH_H
