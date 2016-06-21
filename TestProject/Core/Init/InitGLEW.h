#ifndef InitGLEW_H_
#define InitGLEW_H_

#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

namespace Core {
	namespace Init {

		class InitGLEW
		{
		public:
			static void Init_GLEW();
		};
	}
}

#endif