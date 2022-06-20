
#include"shaderProgram.h"

const char* ShaderProgram::readSource(const char* fileName)
{
	int fileSize;
	FILE* file;
	char* result;

	errno_t err = fopen_s(&file, fileName, "rb");
	if (file != NULL) {
		fseek(file, 0, SEEK_END);
		fileSize = ftell(file);
		fseek(file, 0, SEEK_SET);
		result = new char[fileSize + 1];
		int readsize = fread(result, 1, fileSize, file);
		result[fileSize] = 0;
		fclose(file);
		return result;
	}

	return NULL;
}

ShaderProgram::ShaderProgram(const char* vertexSourceFile, const char* fragmentSourceFile)
{
	const char* vertexShaderSource = readSource(vertexSourceFile);
	const char* fragmentShaderSource = readSource(fragmentSourceFile);

	if (vertexShaderSource == NULL)
	{
		std::cout << "Failed to load vertex shader source file at path: " << vertexSourceFile << std::endl;
		exit(1);
	}
	if (fragmentShaderSource == NULL)
	{
		std::cout << "Failed to load fragment shader source file at path: " << fragmentSourceFile << std::endl;
		exit(1);
	}

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	catchCompilationErrors(vertexShader, "VERTEX");

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	catchCompilationErrors(fragmentShader, "FRAGMENT");

	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	catchCompilationErrors(ID, "PROGRAM");

	delete[]vertexShaderSource;
	delete[]fragmentShaderSource;
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void ShaderProgram::Use()
{
	glUseProgram(ID);
}

void ShaderProgram::Delete()
{
	glDeleteProgram(ID);
}

void ShaderProgram::catchCompilationErrors(GLuint objectID, const char* type)
{
	GLint success;
	GLchar infoLog[512];
	if (type != "PROGRAM")
	{
		glGetShaderiv(objectID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(objectID, 512, NULL, infoLog);
			std::cout << "Error compiling " << type << " shader\n" << infoLog << std::endl;
		}
	}
	else
	{
		glGetProgramiv(objectID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(objectID, 512, NULL, infoLog);
			std::cout << "Error linking shader program\n" << infoLog << std::endl;
		}
	}
}