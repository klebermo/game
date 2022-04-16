#include "Shape3d.h"

Shape3d::Shape3d() {
  //
}

Shape3d::~Shape3d() {
  //
}

GLuint Shape3d::loadShader(GLuint type, const GLchar* shaderCode) {
  GLuint shader = glCreateShader(type);
  glShaderSource(shader, 1, &shaderCode, NULL);
  glCompileShader(shader);
  return shader;
}
