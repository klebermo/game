#include "Renderer3d.h"

Renderer3d::Renderer3d() {
  //
}

Renderer3d::~Renderer3d() {
  //
}

void Renderer3d::drawFrame(SDL_Window * window) {
  SDL_GLContext context = SDL_GL_CreateContext(window);

  glewExperimental = GL_TRUE;
  glewInit();

  while(true) {
    if(input.pollEvent()) {
      if (input.getEvent().type == SDL_QUIT) break;
      if (input.getEvent().type == SDL_KEYUP && input.getEvent().key.keysym.sym == SDLK_ESCAPE) break;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    this->world = new World();
    world->draw();

    SDL_GL_SwapWindow(window);
  }

  SDL_GL_DeleteContext(context);
}
