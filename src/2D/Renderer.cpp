#include "Renderer.h"

Renderer::Renderer() {
  //
}

Renderer::~Renderer() {
  //
}

std::vector<Image> Renderer::getImages() {
  return this->images;
}

void Renderer::drawFrame(SDL_Window * window) {
  SDL_GLContext context = SDL_GL_CreateContext(window);

  glewExperimental = GL_TRUE;
  glewInit();

  for(int i=0; i<images.size(); i++) images[i].init();

  while(true) {
    if(input.pollEvent()) {
      if(input.getEvent().type == SDL_QUIT) break;
      if(input.getEvent().type == SDL_KEYUP && input.getEvent().key.keysym.sym == SDLK_ESCAPE) break;
    }

    for(int i=0; i<images.size(); i++) images[i].draw();

    SDL_GL_SwapWindow(window);
  }

  SDL_GL_DeleteContext(context);
}
