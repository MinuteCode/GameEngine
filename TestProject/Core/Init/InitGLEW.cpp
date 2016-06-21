#include "stdafx.h"
#include "InitGLEW.h"

using namespace Core;
using namespace Core::Init;

void InitGLEW::Init_GLEW()
{
	glewExperimental = true;
	if (glewInit() == GLEW_OK)
		std::cout << "GLEW : Initialiaze" << std::endl;

	if (glewIsSupported("GL_VERSION_4_5"))
		std::cout << "GLEW GL version is 4.5" << std::endl;
	else
		std::cout << "GLEW GL version 4.5 not supported" << std::endl;
}