#ifndef SHAPE2D_H
#define SHAPE2D_H

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

class Shape2d {
protected:
  GLuint vao;
  GLuint vbo;
  GLuint mProgram;
  GLuint vertexShader;
  GLuint fragmentShader;

  GLuint loadShader(GLuint type, const GLchar* shaderCode);
public:
  Shape2d();
  ~Shape2d();

  virtual void draw() = 0;
  virtual const GLchar * vertexShaderCode() = 0;
  virtual const GLchar * fragmentShaderCode() = 0;
};

#endif //SHAPE2D_H
