#include "Surface2d.h"

int main(int argc, char ** argv) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    return 0;
  } else {
    cout << "1" << endl;
    Surface * surface = new Surface2d();
    cout << "2" << endl;
    surface->setRenderer(Renderer());
    cout << "3" << endl;
    surface->loop();
    cout << "4" << endl;
  }
  SDL_Quit();
  return 1;
}
