#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

namespace Managers
{

	class ShaderManager
	{
	public:
		ShaderManager();
		~ShaderManager();

		void CreateShader(const std::string& shaderName,
							const std::string& vertexShaderFilename, 
							const std::string& fragmentShaderFilename);
		static const GLuint GetShader(const std::string& shaderName);
		void DeleteShader(const std::string& shaderName);

	private:
		std::string ReadShader(const std::string& filename);
		GLuint CreateShader(GLenum shaderType, 
							const std::string& source, 
							const std::string& shaderName);
		static std::map<std::string, GLuint> programs;
	
	};

}

