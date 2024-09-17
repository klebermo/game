#include "Renderer.hpp"

Renderer::Renderer() {
  //
}

Renderer::~Renderer() {
  //
}

void Renderer::setImage(float * vertices, int width, int height) {
  image = new Image(vertices, width, height);
}

void Renderer::drawFrame() {
  glewExperimental = GL_TRUE;
  glewInit();

  image->init();

  while(true) {
    image->draw();
  }

  image->exit();
}
