#include "Renderer2d.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

Renderer2d::Renderer2d() {
  //
}

Renderer2d::~Renderer2d() {
  //
}

void Renderer2d::drawFrame(SDL_Window * window) {
  SDL_GLContext context = SDL_GL_CreateContext(window);

  glewExperimental = GL_TRUE;
  glewInit();

  while(true) {
    if(input.pollEvent()) {
      if (input.getEvent().type == SDL_QUIT) break;
      if (input.getEvent().type == SDL_KEYUP && input.getEvent().key.keysym.sym == SDLK_ESCAPE) break;
    }

    world->draw();

    SDL_GL_SwapWindow(window);
  }

  SDL_GL_DeleteContext(context);
}
