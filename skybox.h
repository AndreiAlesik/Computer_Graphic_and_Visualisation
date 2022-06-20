#ifndef SKYBOX_H
#define SKYBOX_H

#include<vector>
#include<string>

#include"shaderProgram.h"
#include"camera.h"

#include<glad/glad.h>
#include<stb/stb_image.h>
#include"VBO.h"
#include"VAO.h"

class Skybox
{
private:
    unsigned int textureID;
    VAO _VAO;
    std::vector<std::string> faces
    {
        "textures/skybox/right.jpg",
        "textures/skybox/left.jpg",
        "textures/skybox/top.jpg",
        "textures/skybox/bottom.jpg",
        "textures/skybox/front.jpg",
        "textures/skybox/back.jpg"
    };
    std::vector<Vertex> skyboxVertices
    {
        // coords
        Vertex{glm::vec3(-1.0f,  1.0f, -1.0f)},
        Vertex{glm::vec3(-1.0f, -1.0f, -1.0f)},
        Vertex{glm::vec3(1.0f, -1.0f, -1.0f)},
        Vertex{glm::vec3(1.0f, -1.0f, -1.0f)},
        Vertex{glm::vec3(1.0f,  1.0f, -1.0f)},
        Vertex{glm::vec3(-1.0f,  1.0f, -1.0f)},

        Vertex{glm::vec3(-1.0f, -1.0f,  1.0f)},
        Vertex{glm::vec3(-1.0f, -1.0f, -1.0f)},
        Vertex{glm::vec3(-1.0f,  1.0f, -1.0f)},
        Vertex{glm::vec3(-1.0f,  1.0f, -1.0f)},
        Vertex{glm::vec3(-1.0f,  1.0f,  1.0f)},
        Vertex{glm::vec3(-1.0f, -1.0f,  1.0f)},

        Vertex{glm::vec3(1.0f, -1.0f, -1.0f)},
        Vertex{glm::vec3(1.0f, -1.0f,  1.0f)},
        Vertex{glm::vec3(1.0f,  1.0f,  1.0f)},
        Vertex{glm::vec3(1.0f,  1.0f,  1.0f)},
        Vertex{glm::vec3(1.0f,  1.0f, -1.0f)},
        Vertex{glm::vec3(1.0f, -1.0f, -1.0f)},

        Vertex{glm::vec3(-1.0f, -1.0f,  1.0f)},
        Vertex{glm::vec3(-1.0f,  1.0f,  1.0f)},
        Vertex{glm::vec3(1.0f,  1.0f,  1.0f)},
        Vertex{glm::vec3(1.0f,  1.0f,  1.0f)},
        Vertex{glm::vec3(1.0f, -1.0f,  1.0f)},
        Vertex{glm::vec3(-1.0f, -1.0f,  1.0f)},

        Vertex{glm::vec3(-1.0f,  1.0f, -1.0f)},
        Vertex{glm::vec3(1.0f,  1.0f, -1.0f)},
        Vertex{glm::vec3(1.0f,  1.0f,  1.0f)},
        Vertex{glm::vec3(1.0f,  1.0f,  1.0f)},
        Vertex{glm::vec3(-1.0f,  1.0f,  1.0f)},
        Vertex{glm::vec3(-1.0f,  1.0f, -1.0f)},

        Vertex{glm::vec3(-1.0f, -1.0f, -1.0f)},
        Vertex{glm::vec3(-1.0f, -1.0f,  1.0f)},
        Vertex{glm::vec3(1.0f, -1.0f, -1.0f)},
        Vertex{glm::vec3(1.0f, -1.0f, -1.0f)},
        Vertex{glm::vec3(-1.0f, -1.0f,  1.0f)},
        Vertex{glm::vec3(1.0f, -1.0f,  1.0f)}
    };
public:
    Skybox();
    unsigned int loadTextures();
    void Draw(ShaderProgram& shader, Camera& camera);
};

#endif // !SKYBOX