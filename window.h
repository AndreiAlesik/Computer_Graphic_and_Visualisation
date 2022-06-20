#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include"Model.h"
#include"skybox.h"
#include"smoke.h"
#include"Controller.h"
#include"camera.h"

class Window
{
private:
	const char* _title;
	int _width, _height;
	GLFWwindow* _window;

	std::vector<ShaderProgram> _shaderPrograms;

	void Init();

public:
	Window(const char* title, int width, int height);
	~Window();
	void initShaders();
	void StartMainLoop();
};

#endif
