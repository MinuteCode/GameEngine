// main.cpp : Defines the entry point for the console application.
//

#pragma once
#include "stdafx.h"
#include "Core\Init\InitGLUT.h"
#include "Managers\SceneManager.h"
#include "Rendering\Models\Cube.h"


using namespace Core;
using namespace Init;

int main(int argc, char** argv)
{
	WindowInfo window(std::string("GameEngine Start"), 800, 600, 300, 300, true);
	ContextInfo context(4, 5, true);
	FramebufferInfo framebuffer(true, true, true, true);
	InitGLUT::Init_GLUT(window, context, framebuffer);

	Managers::SceneManager* scene = new Managers::SceneManager();
	InitGLUT::SetListener(scene);

	Rendering::Models::Cube* cube = new Rendering::Models::Cube();
	cube->SetProgram(Managers::ShaderManager::GetShader("colorShader"));
	cube->Create();

	scene->GetModelsManager()->SetModel("cube", cube);
	
	InitGLUT::Run();

	delete scene;

    return 0;
}

