#include "Renderer.h"

Renderer::Renderer() {
  //
}

Renderer::~Renderer() {
  //
}

void Renderer::drawFrame() {
  world.draw();
}

void Renderer::surfaceChanged(int width, int height) {
  glViewport(0, 0, width, height);
}
