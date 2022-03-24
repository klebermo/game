#include "Shape.h"

Shape::Shape() {
  //
}

Shape::~Shape() {
  //
}

GLuint Shape::loadShader(GLuint type, const GLchar* shaderCode) {
  GLuint shader = glCreateShader(type);
  glShaderSource(shader, 1, &shaderCode, NULL);
  glCompileShader(shader);
  return shader;
}
