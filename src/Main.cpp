#include "Surface2d.h"

int main(int argc, char ** argv) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    return 0;
  } else {
    Surface * view = new Surface2d();
    view->setRenderer(Renderer());
    view->loop();
  }
  SDL_Quit();
  return 1;
}
