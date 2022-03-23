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
  this->renderer = new Renderer3d();
  renderer->drawFrame();
  SDL_GL_SwapWindow(window);
}
