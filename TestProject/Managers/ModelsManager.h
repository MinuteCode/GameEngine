#pragma once
#include <map>
#include "ShaderManager.h"
#include "../Rendering/IGameObject.h"
#include "../Rendering/Models/Triangle.h"
#include "../Rendering/Models/Quad.h"

using namespace Rendering;

namespace Managers
{
	class ModelsManager
	{
	public:
		ModelsManager();
		~ModelsManager();

		void Draw(glm::mat4& projectionMatrix, glm::mat4& viewMatrix);
		void Update();
		void DeleteModel(const std::string& modelName);
		const IGameObject& GetModel(const std::string& modelName) const;
		void SetModel(const std::string& modelName, IGameObject* object);

	private:
		std::map<std::string, IGameObject*>	gameModelsList;
	};
}
