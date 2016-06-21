#include "stdafx.h"
#include "Model.h"

using namespace Rendering;
using namespace Models;

Model::Model()
{
}


Model::~Model()
{
}

void Model::Draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix)
{

}

void Model::Update()
{

}

void Model::SetProgram(GLuint program)
{
	this->program = program;
}

GLuint Model::GetVao() const
{
	return vao;
}

const std::vector<GLuint>& Model::GetVbos() const
{
	return vbos;
}

void Model::Destroy()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(vbos.size(), &vbos[0]);
	vbos.clear();
}

