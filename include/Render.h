#pragma once

namespace Render
{

bool OpenGLInit(int* argc, char** argv);
void RenderCallback();
void CreateVertexBuffer();
void CompileShaders();
void Render();

}
