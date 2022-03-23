#include "Surface.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

Surface::Surface() {
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

  window = SDL_CreateWindow( "...", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
  if(window != NULL) {
    context = SDL_GL_CreateContext(window);
    surface = SDL_GetWindowSurface(window);
  }

  glewExperimental = GL_TRUE;
  glewInit();
}

Surface::Surface(string windows_title) {
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

  window = SDL_CreateWindow( windows_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
  if(window != NULL) {
    context = SDL_GL_CreateContext(window);
    surface = SDL_GetWindowSurface(window);
  }

  glewExperimental = GL_TRUE;
  glewInit();
}

Surface::~Surface() {
  SDL_DestroyWindow(window);
  SDL_GL_DeleteContext(context);
}
