#ifndef SHAPE_H
#define SHAPE_H

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <iostream>
using namespace std;

#include <string>
using namespace std;

#include <vector>
using namespace std;

#include <memory>
using namespace std;

class Shape {
protected:
  GLuint vao;
  GLuint vbo;
  GLuint mProgram;
  GLuint vertexShader;
  GLuint fragmentShader;

  GLuint loadShader(GLuint type, const GLchar* shaderCode);
public:
  Shape();
  ~Shape();

  virtual void draw() = 0;
  virtual vector<float> vertices() = 0;
  virtual string vertexShaderCode() = 0;
  virtual string fragmentShaderCode() = 0;
};

#endif //SHAPE_H
