#include "Renderer.h"

Renderer::Renderer() {
  //
}

Renderer::~Renderer() {
  //
}

void Renderer::setImage(float * vertices, int width, int height) {
  image = new Image(vertices, width, height);
}

void Renderer::drawFrame(SDL_Window * window) {
  SDL_GLContext context = SDL_GL_CreateContext(window);

  glewExperimental = GL_TRUE;
  glewInit();

  image->init();

  while(true) {
    if(input.pollEvent()) {
      if(input.getEvent().type == SDL_QUIT) break;
      if(input.getEvent().type == SDL_KEYUP && input.getEvent().key.keysym.sym == SDLK_ESCAPE) break;
    }

    image->draw();

    SDL_GL_SwapWindow(window);
  }

  image->exit();

  SDL_GL_DeleteContext(context);
}

void Renderer::showAnimation(SDL_Window * window) {
  //
}
