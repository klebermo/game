#include "Surface2d.h"

#include "Renderer2d.h"

Surface2d::Surface2d(string windows_title, int width, int height) : Surface(windows_title, width, height) {
  this->renderer = new Renderer2d();
}

Surface2d::~Surface2d() {
  //
}

void Surface2d::loop() {
  this->renderer->drawFrame(this->window, this->width, this->height, this->vertices);
}
