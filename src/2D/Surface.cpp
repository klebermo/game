#include "Surface.hpp"

Surface::Surface(std::string windows_title, int width, int height) {
  this->width = width;
  this->height = height;
  this->renderer = new Renderer();
}

Surface::~Surface() {
  delete renderer;
}

Renderer * Surface::getRenderer() {
  return renderer;
}

void Surface::loop() {
  renderer->drawFrame();
}
