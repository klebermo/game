#include "Surface.h"

Surface::Surface(std::string windows_title, int width, int height) {
  this->width = width;
  this->height = height;
  this->renderer = new Renderer();

  SDL_Init(SDL_INIT_VIDEO);

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

  window = SDL_CreateWindow( windows_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL );
}

Surface::~Surface() {
  SDL_DestroyWindow(window);  
  delete renderer;
}

Renderer * Surface::getRenderer() {
  return this->renderer;
}

void Surface::loop() {
  this->renderer->drawFrame(window);
}
