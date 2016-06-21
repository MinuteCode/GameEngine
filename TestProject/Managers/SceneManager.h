#pragma once
#include "ShaderManager.h"
#include "ModelsManager.h"
#include "../Core/Init/IListener.h"

namespace Managers {

	class SceneManager : public Core::IListener
	{
	public:
		SceneManager();
		~SceneManager();
		virtual void NotifyBeginFrame();
		virtual void NotifyDisplayFrame();
		virtual void NotifyEndFrame();
		virtual void NotifyReshape(int width,
									int height,
									int previous_width,
									int previous_height);
		ModelsManager* GetModelsManager() { return modelsManager; }

	private:
		Managers::ShaderManager* shaderManager;
		Managers::ModelsManager* modelsManager;
		glm::mat4 viewMatrix, projectionMatrix;
	};
}

