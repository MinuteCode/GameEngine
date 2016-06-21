#include "stdafx.h"
#include "InitGLUT.h"

using namespace Core::Init;

Core::IListener* InitGLUT::listener = NULL;
Core::WindowInfo InitGLUT::windowInformation;

void InitGLUT::Init_GLUT(const Core::WindowInfo& window, const Core::ContextInfo& context, const Core::FramebufferInfo& framebuffer)
{
	int fakeargc = 1;
	char *fakeargv[] = { "fake", NULL };
	glutInit(&fakeargc, fakeargv);

	if (context.core)
	{
		glutInitContextVersion(context.major_version, context.minor_version);
		glutInitContextProfile(GLUT_CORE_PROFILE);
	}
	else
	{
		glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	}

	glutInitDisplayMode(framebuffer.flags);
	glutInitWindowPosition(window.position_x, window.position_y);
	glutInitWindowSize(window.width, window.height);
	glutCreateWindow(window.name.c_str());

	std::cout << "GLUT : Initialized" << std::endl;
	glEnable(GL_DEBUG_OUTPUT);
	

	glutIdleFunc(IdleCallback);
	glutCloseFunc(CloseCallback);
	glutDisplayFunc(DisplayCallback);
	glutReshapeFunc(ReshapeCallback);

	windowInformation = window;

	InitGLEW::Init_GLEW();
	glDebugMessageCallback(DebugOutput::DebugCallback, NULL);
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	PrintOpenGLInfo(window, context);

}

void InitGLUT::Run()
{
	std::cout << "GLUT : Start running" << std::endl;
	glutMainLoop();
}

void InitGLUT::Close()
{
	std::cout << "GLUT : Finished" << std::endl;
	glutLeaveMainLoop();
}

void InitGLUT::IdleCallback(void)
{
	glutPostRedisplay();
}

void InitGLUT::DisplayCallback()
{
	if (listener)
	{
		listener->NotifyBeginFrame();
		listener->NotifyDisplayFrame();

		glutSwapBuffers();

		listener->NotifyEndFrame();
	}
	/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutSwapBuffers();*/
}

void InitGLUT::ReshapeCallback(int width, int height)
{
	if (windowInformation.isReshapable)
	{
		if (listener)
		{
			listener->NotifyReshape(width, height, windowInformation.width, windowInformation.height);
		}
		windowInformation.width = width;
		windowInformation.height = height;
	}

}

void InitGLUT::CloseCallback()
{
	Close();
}

void InitGLUT::EnterFullscreen()
{
	glutFullScreen();
}

void InitGLUT::ExitFullscreen()
{
	glutLeaveFullScreen();
}

void InitGLUT::PrintOpenGLInfo(const Core::WindowInfo& windowInfo,
	const Core::ContextInfo& contextInfo) {

	const unsigned char* renderer = glGetString(GL_RENDERER);
	const unsigned char* vendor = glGetString(GL_VENDOR);
	const unsigned char* version = glGetString(GL_VERSION);

	std::cout << "******************************************************               ************************" << std::endl;
	std::cout << "GLUT:Initialize" << std::endl;
	std::cout << "GLUT:\tVendor : " << vendor << std::endl;
	std::cout << "GLUT:\tRenderer : " << renderer << std::endl;
	std::cout << "GLUT:\tOpenGl version: " << version << std::endl;
}

void InitGLUT::SetListener(Managers::SceneManager*& iListener)
{
	listener = iListener;
}