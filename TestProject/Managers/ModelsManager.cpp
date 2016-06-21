#include "stdafx.h"
#include "ModelsManager.h"

using namespace Managers;
using namespace Rendering;

ModelsManager::ModelsManager()
{
}


ModelsManager::~ModelsManager()
{
	for (auto model : gameModelsList)
	{
		delete model.second;
	}
	gameModelsList.clear();
}

void ModelsManager::DeleteModel(const std::string& modelName)
{
	IGameObject* model = gameModelsList[modelName];
	model->Destroy();
	gameModelsList.erase(modelName);
}

const IGameObject& ModelsManager::GetModel(const std::string& modelName) const
{
	return (*gameModelsList.at(modelName));
}

void ModelsManager::SetModel(const std::string& modelName, IGameObject* object)
{
	gameModelsList[modelName.c_str()] = object;
}

void ModelsManager::Update()
{
	for (auto model : gameModelsList)
		model.second->Update();
}

void ModelsManager::Draw(glm::mat4& projectionMatrix, glm::mat4& viewMatrix)
{
	for (auto model : gameModelsList)
		model.second->Draw(projectionMatrix, viewMatrix);
}

