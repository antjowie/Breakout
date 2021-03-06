#pragma once
#include <vector>

class Shader
{
private:
	std::vector<unsigned> m_shaders;

public:
	~Shader();

	bool addShader(int shaderType, const char* shaderPath);
	// Does error checking for ya
	bool linkProgram(unsigned program);
};