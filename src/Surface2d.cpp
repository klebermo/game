#include "Surface2d.h"

#include "Renderer2d.h"

Surface2d::Surface2d(string windows_title, int width, int height) : Surface(windows_title, width, height) {
  //
}

Surface2d::~Surface2d() {
  //
}

void Surface2d::loop(float * array) {
  Renderer2d renderer;
  renderer.drawFrame(this->window, array);
}
