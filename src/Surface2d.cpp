#include "Surface2d.h"

#include "Renderer2d.h"

Surface2d::Surface2d() {
  //
}

Surface2d::Surface2d(string windows_title) {
  //
}

Surface2d::~Surface2d() {
  //
}

void Surface2d::loop() {
  this->renderer = new Renderer2d();
  renderer->drawFrame();
  SDL_GL_SwapWindow(window);
}
