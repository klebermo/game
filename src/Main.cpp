#include "Surface2d.h"

#include "netpbm.h"

int main(int argc, char ** argv) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    return 0;
  } else {
    Bitmap bitmap;
    bitmap.read_file("letra_jota.pbm");
    Surface * view = new Surface2d("image", bitmap.getWidth(), bitmap.getHeight());
    view->loop(bitmap.toArray());
  }
  SDL_Quit();
  return 1;
}
