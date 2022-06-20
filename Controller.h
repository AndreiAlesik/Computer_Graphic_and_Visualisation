#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <GLFW/glfw3.h>

class Controller
{
	public:
		bool FORWARD_PRESSED = false;
		bool BACK_PRESSED = false;
		bool RIGHT_PRESSED = false;
		bool LEFT_PRESSED = false;

		bool MOUSE_MOVEMENT = false;
		float xMov = 0.0f;
		float yMov = 0.0f;

		bool EXTRA_OPTION1 = false;
		bool EXTRA_OPTION2 = false;
		bool EXTRA_OPTION3 = false;

		Controller(GLFWwindow* window, int width, int height) :
			_window(window), _width(width), _height(height) {};
		void handleInputs();
	private:
		GLFWwindow* _window;
		float _mouseSensitivity = 70.0f;
		bool _firstClick = false;
		bool _alternativeControls = true;
		int _width;
		int _height;
};

#endif // !CONTROLLER_H


