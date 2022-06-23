#include "Surface.h"

Surface::Surface(string windows_title, int width, int height, float * vertices) {
  this->width = width;
  this->height = height;

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

  window = SDL_CreateWindow( windows_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->width, this->height, SDL_WINDOW_OPENGL );
  renderer = new Renderer(new Image(vertices, width, height));
}

Surface::~Surface() {
    SDL_DestroyWindow(window);
    delete renderer;
}

void Surface::loop() {
  this->renderer->drawFrames(window);
}
