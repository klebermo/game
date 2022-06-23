#ifndef WORLD_H
#define WORLD_H

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

class Image {
private:
  float * vertexList;
  int width;
  int height;

  GLuint vao;
  GLuint vbo;
  GLuint mProgram;
  GLuint vertexShader;
  GLuint fragmentShader;

  const GLchar * vertexShaderCode();
  const GLchar * fragmentShaderCode();
  GLuint loadShader(GLuint type, const GLchar* shaderCode);
public:
  Image(float * values, int width, int height);
  ~Image();

  float * getVertices();
  int getWidth();
  int getHeight();
  int getSize();

  void draw();
};

#endif //WORLD_H
