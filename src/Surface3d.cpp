#include "Surface3d.h"

#include "Renderer3d.h"

Surface3d::Surface3d() {
  //
}

Surface3d::Surface3d(string windows_title) {
  //
}

Surface3d::~Surface3d() {
  //
}

void Surface3d::loop() {
  Renderer3d renderer;
  renderer.drawFrame(this->window);
}
