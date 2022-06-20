#include"Controller.h"

void Controller::handleInputs()
{
	// KEYBOARD INPUT
	if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS)
	{
		FORWARD_PRESSED = true;
	}
	if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_RELEASE)
	{
		FORWARD_PRESSED = false;
	}
	if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS)
	{
		BACK_PRESSED = true;
	}
	if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_RELEASE)
	{
		BACK_PRESSED = false;
	}
	if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS)
	{
		LEFT_PRESSED = true;
	}
	if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_RELEASE)
	{
		LEFT_PRESSED = false;
	}
	if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS)
	{
		RIGHT_PRESSED = true;
	}
	if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_RELEASE)
	{
		RIGHT_PRESSED = false;
	}
	if (glfwGetKey(_window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		EXTRA_OPTION1 = true;
	}
	else if (glfwGetKey(_window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
	{
		EXTRA_OPTION1 = false;
	}
	if (glfwGetKey(_window, GLFW_KEY_G) == GLFW_PRESS)
	{
		EXTRA_OPTION2 = true;
	}
	else if (glfwGetKey(_window, GLFW_KEY_G) == GLFW_RELEASE)
	{
		EXTRA_OPTION2 = false;
	}
	
	//MOUSE INPUT
	if (!_alternativeControls)
	{
		if (glfwGetMouseButton(_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		{
			glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

			if (_firstClick)
			{
				glfwSetCursorPos(_window, (_width / 2), (_height / 2));
				_firstClick = false;
			}

			double mouseX;
			double mouseY;
			glfwGetCursorPos(_window, &mouseX, &mouseY);

			MOUSE_MOVEMENT = true;

			xMov = _mouseSensitivity * (float)(mouseY - (_height / 2)) / _height;
			yMov = _mouseSensitivity * (float)(mouseX - (_width / 2)) / _width;

			glfwSetCursorPos(_window, (_width / 2), (_height / 2));
		}
		else if (glfwGetMouseButton(_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
		{
			glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			_firstClick = true;
			MOUSE_MOVEMENT = false;
		}
	}
	if (_alternativeControls)
	{
		if (glfwGetMouseButton(_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && !_firstClick)
		{
			_firstClick = true;
			glfwSetCursorPos(_window, (_width / 2), (_height / 2));
		}
		if (_firstClick)
		{
			glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

			double mouseX;
			double mouseY;
			glfwGetCursorPos(_window, &mouseX, &mouseY);

			MOUSE_MOVEMENT = true;

			xMov = _mouseSensitivity * (float)(mouseY - (_height / 2)) / _height;
			yMov = _mouseSensitivity * (float)(mouseX - (_width / 2)) / _width;

			glfwSetCursorPos(_window, (_width / 2), (_height / 2));
		}
		if (glfwGetMouseButton(_window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
		{
			_firstClick = false;
			MOUSE_MOVEMENT = false;
			glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}
	}
}