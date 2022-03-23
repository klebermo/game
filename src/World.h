#ifndef WORLD_H

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <iostream>
using namespace std;

#include <string>
using namespace std;

class World {
protected:
  GLuint vao;
  GLuint vbo;
  GLuint vertexShader;
  GLuint fragmentShader;
  GLuint shaderProgram;

  GLuint loadShader(GLuint type, const GLchar* shaderCode);
public:
  World();
  ~World();
  void draw();
};

#endif //WORLD_H
