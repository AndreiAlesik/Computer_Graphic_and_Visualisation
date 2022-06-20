#include "window.h"

Window::Window(const char* title, int width, int height)
{
	_title = title;
	_width = width;
	_height = height;
	Init();
}

Window::~Window()
{
	glfwDestroyWindow(_window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

void Window::Init()
{
	if (!glfwInit()) {
		std::cerr << "Can't inicialize GLFW" << std::endl;
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	_window = glfwCreateWindow(_width, _height, _title, NULL, NULL);
	if (!_window)
	{
		std::cerr << "Can't create window" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(_window);

	gladLoadGL();
	glViewport(0, 0, _height, _width);

	glfwSwapInterval(1);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(_window);

	initShaders();
}

void Window::initShaders()
{
	_shaderPrograms.push_back(ShaderProgram("shaders/model/model.vert", "shaders/model/model.frag"));
	_shaderPrograms.push_back(ShaderProgram("shaders/skybox/skybox.vert", "shaders/skybox/skybox.frag"));
	_shaderPrograms.push_back(ShaderProgram("shaders/water/water.vert", "shaders/water/water.frag"));
	_shaderPrograms.push_back(ShaderProgram("shaders/smoke/smoke.vert", "shaders/smoke/smoke.frag"));
}

void Window::StartMainLoop()
{
	Skybox skybox;
	Smoke smoke;

	Model water("models/water/water.gltf");
	Model model("models/WW2/14083_WWII_ship - UK - King_George_V_Class_Battleship_v1_L1.obj");

	Camera cam(_window, _width, _height);
	Controller controller(_window, _width, _height);

	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	_shaderPrograms[0].Use();
	_shaderPrograms[0].setVec4("lightColor", lightColor);
	model.Scale(glm::vec3(10.0f, 10.0f, 10.0f), _shaderPrograms[0]);
	model.Rotate(glm::vec3(1.0f, 0.0f, 0.0f), -90.0f, _shaderPrograms[0]);
	
	water.Scale(glm::vec3(30.0f, 30.0f, 30.0f), _shaderPrograms[2]);
	_shaderPrograms[2].Use();

	//timer
	float oldTime = glfwGetTime();
	float curTime;
	float timer = 0.0f;

	while (!glfwWindowShouldClose(_window))
	{
		controller.handleInputs();
		
		//timer
		curTime = glfwGetTime();
		if ((curTime - oldTime) >= 0.01f)
		{
			oldTime = curTime;
			timer += 0.05f;
		}

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		cam.Loop(controller);

		_shaderPrograms[0].Use();
		model.Move(glm::vec3(0.0f, sin(timer / 1.5f) / 10.0f - 0.3f, 0.0f), _shaderPrograms[0]);
		model.Draw(_shaderPrograms[0], cam);

		_shaderPrograms[2].Use();
		_shaderPrograms[2].setFloat("time", timer);
		water.Draw(_shaderPrograms[2], cam);

		_shaderPrograms[1].Use();
		skybox.Draw(_shaderPrograms[1], cam);

		_shaderPrograms[3].Use();
		smoke.Draw(_shaderPrograms[3], cam);

		glfwSwapBuffers(_window);
		glfwPollEvents();
	}
}
