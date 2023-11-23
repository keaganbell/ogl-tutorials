#include "Render.h"

#include <spdlog/spdlog.h>

#include <iostream>

int main(int argc, char** argv)
{
    if (Render::OpenGLInit(&argc, argv) == false)
        return 1;

    Render::CreateVertexBuffer();

    Render::CompileShaders();

    Render::Render();

    return 0;
}
