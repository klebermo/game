#include "Surface2d.h"
#include "Renderer2d.h"

#include "netpbm.h"

#include <sstream>
using namespace std;

int main(int argc, char ** argv) {
  if (argc < 2) {
    cout << "Usage: game <file_name>" << endl;
    return 0;
  }

  if (SDL_Init(SDL_INIT_VIDEO) >= 0) {
    string file_name(argv[1]);
    string extension;
    stringstream ss(file_name);
    while(getline(ss, extension, '.'));

    Netpbm * image;
    int width = 0, height = 0;
    float * vertices = NULL;

    if(extension == "pbm") {
      image = new Bitmap(argv[1]);
      width = image->getWidth(), height = image->getHeight(), vertices = image->toArray();
    }

    if(extension == "pgm") {
      image = new Graymap(argv[1]);
      width = image->getWidth(), height = image->getHeight(), vertices = image->toArray();
    }

    if(extension == "ppm") {
      image = new Pixmap(argv[1]);
      width = image->getWidth(), height = image->getHeight(), vertices = image->toArray();
    }

    Surface * view = new Surface2d("image", width, height);
    view->setVertices(vertices);
    view->loop();

    delete vertices;
    delete image;

    SDL_Quit();
  }

  return 1;
}
