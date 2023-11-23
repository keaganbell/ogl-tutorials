#include "Render.h"

#include <spdlog/spdlog.h>

#include "GL/glew.h"
#include "glut.h"
#include "glm/glm.hpp"

static GLuint VBO;

bool Render::OpenGLInit(int* argc, char** argv)
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tutorial 01");
    
    GLenum res = glewInit();
    if (res != GLEW_OK)
    {
        spdlog::error("Glew Init Failed: {0}\n", glewGetErrorString(res));
        return false;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    return true;
}

void Render::RenderCallback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);
    glutSwapBuffers();
}

void Render::CreateVertexBuffer()
{
    glm::vec3 vertices[3];
    vertices[0] = glm::vec3(-0.5f, -0.5f,  0.0f);
    vertices[1] = glm::vec3( 0.5f, -0.5f,  0.0f);
    vertices[2] = glm::vec3( 0.0f,  0.75f, 0.0f);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
}

void Render::CompileShaders()
{
//    GLuint shader_program = glCreateProgram();
//    GLuint shader_object  = glCreatShader(ShaderType);
}

void Render::Render()
{
    glutDisplayFunc(Render::RenderCallback);
    glutMainLoop();
}
