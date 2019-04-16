#pragma once

class InputHandler;
struct GLFWwindow;

class Game {
protected:
  GLFWwindow *m_window;
  InputHandler *m_inputHandler;

public:
  virtual ~Game();

  bool init(GLFWwindow *window, InputHandler *InputHandler);

  virtual bool onCreate() = 0;
  virtual void handleInput(double elapsedTime) = 0;
  virtual void update(double elapsedTime) = 0;
  virtual void render() = 0;
};