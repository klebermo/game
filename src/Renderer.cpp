#include "Renderer.h"

Renderer::Renderer() {
  //
}

Renderer::~Renderer() {
  //
}

GLuint Renderer::loadShader(GLuint type, const GLchar* shaderCode) {
  GLuint shader = glCreateShader(type);
  glShaderSource(shader, 1, &shaderCode, NULL);
  glCompileShader(shader);
  return shader;
}
