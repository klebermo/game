#include "Surface3d.h"

#include "Renderer3d.h"

Surface3d::Surface3d(string windows_title, int width, int height) : Surface(windows_title, width, height) {
  this->renderer = new Renderer3d();
}

Surface3d::~Surface3d() {
  //
}

void Surface3d::loop() {
  this->renderer->drawFrame(this->window, this->width, this->height, this->vertices);
}
