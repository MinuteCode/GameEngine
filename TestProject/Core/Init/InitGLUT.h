#ifndef InitGLUT_H_
#define InitGLUT_H_

#pragma once
#include "ContextInfo.h"
#include "FrambufferInfo.h"
#include "WindowInfo.h"
#include "InitGlew.h"
#include "IListener.h"
#include "DebugOutput.h"
#include <iostream>
#include "../../Managers/SceneManager.h"

namespace Core {
	namespace Init {
		
		class InitGLUT {
		public:
			static void	Init_GLUT(const Core::WindowInfo& window,
							const Core::ContextInfo& context,
							const Core::FramebufferInfo& framebuffer);
			static void Run();
			static void Close();
			static void PrintOpenGLInfo(const Core::WindowInfo& window,
										const Core::ContextInfo& context);
			static void SetListener(Managers::SceneManager*& iListener);

			void EnterFullscreen();
			void ExitFullscreen();

		private:
			static Core::IListener* listener;
			static Core::WindowInfo windowInformation;
			static void IdleCallback(void);
			static void DisplayCallback(void);
			static void ReshapeCallback(int width, int height);
			static void CloseCallback();
		};
	}
}

#endif