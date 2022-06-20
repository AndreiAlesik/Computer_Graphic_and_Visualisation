#include"camera.h"

Camera::Camera(GLFWwindow* window, int width, int height, glm::vec3 defaultPosition, glm::vec3 defaultOrientation)
{
	_window = window;
	_width = width;
	_height = height;
	_position = defaultPosition;
	_orientation = defaultOrientation;
}

void Camera::Loop(Controller& controller)
{
	_view = glm::mat4(1.0f);
	_proj = glm::mat4(1.0f);

	handleInputs(controller);

	_view = glm::lookAt(_position, _position + _orientation, _upVector);
	_proj = glm::perspective(glm::radians(_FOV), (float)(_width / _height), 0.1f, 1000.0f);
}

void Camera::cameraSetUniforms(ShaderProgram& shader)
{
	shader.Use();
	shader.setMat4("view", _view);
	shader.setMat4("proj", _proj);
}

void Camera::handleInputs(Controller& controller)
{
	if (controller.FORWARD_PRESSED)
	{
		_position += _movementSpeed * _orientation;
	}
	if (controller.LEFT_PRESSED)
	{
		_position += _movementSpeed * -glm::normalize(glm::cross(_orientation, _upVector));
	}
	if (controller.BACK_PRESSED)
	{
		_position += _movementSpeed * -_orientation;
	}
	if (controller.RIGHT_PRESSED)
	{
		_position += _movementSpeed * glm::normalize(glm::cross(_orientation, _upVector));
	}
	if (controller.EXTRA_OPTION1)
	{
		_movementSpeed = 0.5f;
	}
	else if (!controller.EXTRA_OPTION1)
	{
		_movementSpeed = 0.15f;
	}

	// MOUSE CONTROLS
	if (controller.MOUSE_MOVEMENT)
	{
		float rotX = controller.xMov;
		float rotY = controller.yMov;

		glm::vec3 newOrientation = glm::rotate(_orientation, glm::radians(-rotX), glm::normalize(glm::cross(_orientation, _upVector)));

		if (abs(glm::angle(newOrientation, _upVector) - glm::radians(90.0f)) <= glm::radians(85.0f))
		{
			_orientation = newOrientation;
		}

		_orientation = glm::rotate(_orientation, glm::radians(-rotY), _upVector);
	}
}