#include "SpriteRenderer.h"

#include "Sprite.h"
#include "Shader.h"

#include <glad/glad.h>

#include <iostream>

SpriteRenderer::SpriteRenderer()
{
	// Load shaders
	// ---
	Shader shader;
	m_program = glCreateProgram();

	if (!shader.addShader(GL_VERTEX_SHADER, "resources/shaders/sprite.vert"))
		std::cout << "Sprite vertex shader failed compilation\n";
	if (!shader.addShader(GL_FRAGMENT_SHADER, "resources/shaders/sprite.frag"))
		std::cout << "Sprite fragment shader failed compilation\n";
	if (!shader.linkProgram(m_program))
		std::cout << "Sprite linking program failed\n";

	// Load vertices
	// ---
	// Make the cube
	// well, it is actually a temp triangle
	static const GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		 0.5f, -0.5f, 0.0f, // right 
		 0.0f,  0.5f, 0.0f  // top   
	};
	// Gen buffers
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);
}

void SpriteRenderer::addSprite(const Sprite & sprite)
{
	m_sprites.emplace_back(sprite.m_pos);
}

void SpriteRenderer::display()
{
	// TODO add instancing
	glBindVertexArray(m_vao);
	glUseProgram(m_program);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	//glDrawArraysInstanced(GL_TRIANGLES, 0, 3, m_sprites.size());

	m_sprites.clear();
}