#include "Renderer.h"

Renderer::Renderer() {
  //
}

Renderer::~Renderer() {
  //delete image;
}

void Renderer::addImage(float * vertices, int width, int height) {
  images.push_back(Image(vertices, width, height));
}


/*
void Renderer::setImage(Image * image) {
  this->image = image;
}
*/

void Renderer::drawFrame(SDL_Window * window) {
  SDL_GLContext context = SDL_GL_CreateContext(window);

  glewExperimental = GL_TRUE;
  glewInit();

  for(std::vector<Image>::size_type i=0; i<images.size(); i++) images[i].init();
  //image->init();

  while(true) {
    if(input.pollEvent()) {
      if(input.getEvent().type == SDL_QUIT) break;
      if(input.getEvent().type == SDL_KEYUP && input.getEvent().key.keysym.sym == SDLK_ESCAPE) break;
    }

    for(std::vector<Image>::size_type i=0; i<images.size(); i++) images[i].draw();
    //image->draw();

    SDL_GL_SwapWindow(window);
  }

  for(std::vector<Image>::size_type i=0; i<images.size(); i++) images[i].exit();
  //image->exit();

  SDL_GL_DeleteContext(context);
}
