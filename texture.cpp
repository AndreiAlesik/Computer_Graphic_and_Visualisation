#include"texture.h"

Texture::Texture(const char* imagePath)
{
	GLenum type = GL_TEXTURE_2D;
	glGenTextures(1, &ID);

	int width, height, colorChannels;

	stbi_set_flip_vertically_on_load(true);

	unsigned char* bytes = stbi_load(imagePath, &width, &height, &colorChannels, 0);

	if (bytes)
	{
		GLenum format = GL_RGB;
		if (colorChannels == 1)
		{
			format = GL_RED;
		}
		else if (colorChannels == 3)
		{
			format = GL_RGB;
		}
		else if (colorChannels == 4)
		{
			format = GL_RGBA;
		}

		glBindTexture(GL_TEXTURE_2D, ID);
		glActiveTexture(GL_TEXTURE0);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, bytes);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //smaller
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //bigger

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		stbi_image_free(bytes);
	}
	else
	{
		std::cout << "Failed to load texture at path: " << imagePath << std::endl;
		stbi_image_free(bytes);
	}

	Unbind();
}

void Texture::texUnit(ShaderProgram &shader, const char* uniform, GLuint v)
{
	shader.Use();
	glActiveTexture(v);
	shader.setInt(uniform, v);
}

void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}