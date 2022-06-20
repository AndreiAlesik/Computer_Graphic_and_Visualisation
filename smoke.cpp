#include"smoke.h"

Smoke::Smoke()
{
    texture = new Texture(textureFile.c_str());

    VBO _VBO(smokeVertices);
    _VAO.Bind();
    _VAO.LinkAttrib(_VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, coords));
    _VAO.LinkAttrib(_VBO, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));
}

void Smoke::Draw(ShaderProgram& shader, Camera& camera)
{
    shader.Use();
    glm::mat4 model(1.0f);
    shader.setMat4("proj", camera.getProjMatrix());
    shader.setMat4("model", model);
    _VAO.Bind();
    texture->Bind();
    glDrawArrays(GL_TRIANGLES, 0, 6);
    _VAO.Unbind();
}