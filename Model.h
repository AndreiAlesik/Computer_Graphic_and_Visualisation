#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include<vector>
#include<string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include"shaderProgram.h"
#include"texture.h"
#include"VBO.h"
#include"VAO.h"
#include"EBO.h"
#include"camera.h"
#include"Mesh.h"

#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"
#include"glm/gtc/type_ptr.hpp"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Model
{
	public:
		Model(std::string path);
		void Draw(ShaderProgram& shader, Camera& camera);
		std::vector<Mesh> _meshes;

		void Rotate(glm::vec3 axis, GLfloat angle, ShaderProgram& shader);
		void Move(glm::vec3 translation, ShaderProgram& shader);
		void Scale(glm::vec3 scale, ShaderProgram& shader);
	private:
		std::string directory;
		std::vector<std::string> loadedTextures;

		//model load
		void loadModel(std::string path);
		void processNode(aiNode* node, const aiScene* scene);
		Mesh convertAIMeshToMesh(aiMesh* mesh, const aiScene* scene);
		std::vector<Texture> loadMaterialTextures(aiMaterial* material, aiTextureType type);
};

#endif