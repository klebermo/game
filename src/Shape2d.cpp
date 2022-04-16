#include "Shape2d.h"

Shape2d::Shape2d() {
  //
}

Shape2d::~Shape2d() {
  //
}

GLuint Shape2d::loadShader(GLuint type, const GLchar* shaderCode) {
  GLuint shader = glCreateShader(type);
  glShaderSource(shader, 1, &shaderCode, NULL);
  glCompileShader(shader);
  return shader;
}
