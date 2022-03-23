#include "Surface2d.h"

int main(int argc, char ** argv) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    return 0;
  } else {
    Surface * surface = new Surface2d();
    surface->setRenderer(Renderer());
    surface->loop();
  }
  SDL_Quit();
  return 1;
}
