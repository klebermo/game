#include "Surface3d.h"

#include "Renderer3d.h"

Surface3d::Surface3d(string windows_title, int width, int height) : Surface(windows_title, width, height) {
  //
}

Surface3d::~Surface3d() {
  //
}

void Surface3d::loop(float * array) {
  Renderer3d renderer;
  renderer.drawFrame(this->window, array);
}
