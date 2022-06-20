#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window.h"
#include"shaderProgram.h"
#include"VBO.h"
#include"VAO.h"
#include"EBO.h"

int main()
{
	Window window("OGL", 800, 800);

	window.StartMainLoop();

	return 0;
}