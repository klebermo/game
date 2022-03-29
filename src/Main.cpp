#include "Surface2d.h"

#include "netpbm.h"

int main(int argc, char ** argv) {
  if (argc < 2) {
    cout << "Usage: game <file_name>" << endl;
    return 0;
  }

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    return 0;
  } else {
    Bitmap bitmap;
    bitmap.read_file(argv[1]);
    int width = bitmap.getWidth(), height = bitmap.getHeight();
    float * vertices = bitmap.toArray();
    Surface * view = new Surface2d("image", width, height);
    view->loop(vertices);
    delete vertices;
  }

  SDL_Quit();
  return 1;
}
