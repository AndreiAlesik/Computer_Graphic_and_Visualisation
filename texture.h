#ifndef TEXTURE_H
#define TEXTURE_H

#include<glad/glad.h>
#include<stb/stb_image.h>

#include"shaderProgram.h"

class Texture
{
public:
	GLuint ID;
	GLuint unit;

	//GLenum type;

	Texture(const char* image);
	void texUnit(ShaderProgram &shader, const char* uniform, GLuint v);
	void Bind();
	void Unbind();
	void Delete();
};

#endif // !TEXTURE_H

