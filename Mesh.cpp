#include"Mesh.h"

// Структура Vertex определена в VBO.h

Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<GLuint> &indices, std::vector<Texture> &textures)
{
	_vertices = vertices;
	_indices = indices;
	_textures = textures;

	model = glm::mat4(1.0f);

	rotationMatrix = glm::mat4(1.0f);
	translationMatrix = glm::mat4(1.0f);
	scaleMatrix = glm::mat4(1.0f);

	_VAO.Bind();
	VBO _VBO(_vertices);
	EBO _EBO(_indices);

	//offsetof - смещение вектора в структуре Vertex
	_VAO.LinkAttrib(_VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, coords)); // coords
	_VAO.LinkAttrib(_VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, normal)); //normals
	_VAO.LinkAttrib(_VBO, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, texCoords)); //texCoords

	_VAO.Unbind();
	_VBO.Unbind();
	_EBO.Unbind();
}

void Mesh::Draw(ShaderProgram& shader, Camera &camera)
{
	shader.Use();
	_VAO.Bind();

	for (int i = 0; i < _textures.size(); i++)
	{
		_textures[i].texUnit(shader, "tex", i);
		_textures[i].Bind();
	}

	shader.setVec3("cameraPosition", camera._position);
	camera.cameraSetUniforms(shader);

	applyTransformations(shader);

	//Draw mesh
	glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
}

void Mesh::Rotate(glm::vec3 axis, GLfloat angle, ShaderProgram &shader)
{
	rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(angle), axis);
}

void Mesh::Move(glm::vec3 translation, ShaderProgram& shader)
{
	translationMatrix = glm::translate(glm::mat4(1.0f), translation);
}

void Mesh::Scale(glm::vec3 scale, ShaderProgram& shader)
{
	scaleMatrix = glm::scale(glm::mat4(1.0f), scale);
}

void Mesh::applyTransformations(ShaderProgram& shader)
{
	glm::mat4 transformationMatrix = translationMatrix * rotationMatrix * scaleMatrix;
	glm::mat4 transformedModel = transformationMatrix * model;
	shader.setMat4("model", transformedModel);
}