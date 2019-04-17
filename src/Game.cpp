#include "Game.h"

#include "Shader.h"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void Game::handleInput(double elapsedTime)
{
	if (glfwGetKey(m_windowHandle,GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(m_windowHandle, GLFW_TRUE);
}

void Game::update(double elapsedTime)
{
}

void Game::render()
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

Game::Game(int width, int height, const char * windowTitle):
	m_windowHandle(m_graphics.createWindow(width,height,windowTitle))
{
	//=============
	// Temp rendering
	//=============

	Shader shader;
	unsigned m_program = glCreateProgram();

	if (!shader.addShader(GL_VERTEX_SHADER, "resources/shaders/mesh.vert"))
		std::cout << "Vertex shader failed compilation\n";
	if (!shader.addShader(GL_FRAGMENT_SHADER, "resources/shaders/mesh.frag"))
		std::cout << "Fragment shader failed compilation\n";
	if (!shader.linkProgram(m_program))
		std::cout << "Linking program failed\n";

	glUseProgram(m_program);
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

void Game::run()
{
	glfwSetTime(1. / 60.);

	double totalTime = 0.;
	double elapsedTime = 0.;
	
	unsigned frames = 0;
	double elapsedFrameTime = 0.;

	glClearColor(0.4f, 0.4f, 0.8f, 1.f);
	while (!glfwWindowShouldClose(m_windowHandle))
	{
		// Time
		elapsedTime = glfwGetTime() - totalTime;
		if (elapsedTime > 1.)
			elapsedTime = 1. / 60.;
		totalTime += elapsedTime;

		// Input
		handleInput(elapsedTime);
		update(elapsedTime);
		
		// Render
		glClear(GL_COLOR_BUFFER_BIT);
		render();

		// GLFW stuff
		glfwSwapBuffers(m_windowHandle);
		glfwPollEvents();

		// Framerate
		frames++;
		elapsedFrameTime += elapsedTime;
		if (elapsedFrameTime > 1.)
		{
			std::printf("Rendered %i frames in %.2f seconds => %.2f fps \t| totalTime %.2f\n", 
				frames, elapsedFrameTime, static_cast<double>(frames) / elapsedFrameTime, totalTime);
			frames = 0;
			elapsedFrameTime -= 1.;
		}
	}
}