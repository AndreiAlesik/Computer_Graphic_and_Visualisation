#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"
#include"glm/gtc/type_ptr.hpp"
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include"shaderProgram.h"
#include"Controller.h"

class Camera
{
public:
	GLFWwindow* _window;
	glm::vec3 _position;
	glm::vec3 _orientation;
	glm::mat4 _proj = glm::mat4(1.0f);
	glm::mat4 _view = glm::mat4(1.0f);
	glm::vec3 _upVector = glm::vec3(0.0f, 1.0f, 0.0f);
	
	bool _alternativeControls = true;

	bool _firstClick = false;
	
	int _width;
	int _height;
	float _FOV = 45.0f;

	float _movementSpeed = 0.02f;
	float _mouseSensitivity = 70.0f;

	Camera(GLFWwindow* window, int width, int height, glm::vec3 defaultPosition = glm::vec3(-20.0f, 20.0f, 20.0f), glm::vec3 defaultOrientation = glm::vec3(0.0f, 0.0f, -1.0f));
	void Loop(Controller& controller);
	void cameraSetUniforms(ShaderProgram& shader);
	void handleInputs(Controller& controller);

	glm::mat4 getViewMatrix() { return _view; }
	glm::mat4 getProjMatrix() { return _proj; }
};

#endif // !CAMERA_H
