#include "2D/Surface.h"

#include "netpbm.h"

#include <sstream>
using namespace std;

int main(int argc, char ** argv) {
  if (argc < 2) {
    cout << "Usage: game <file_name>" << endl;
    return 0;
  }

  string file_name(argv[1]);
  string extension;
  stringstream ss(file_name);
  while(getline(ss, extension, '.'));

  Netpbm * image;
  int width = 0, height = 0;
  float * vertices = nullptr;

  if(extension == "pbm") {
    image = new Bitmap(argv[1]);
    width = image->getWidth(), height = image->getHeight(), vertices = image->toArray();
  }

  if(extension == "pgm") {
    image = new Graymap(argv[1]);
    width = image->getWidth(), height = image->getHeight(), vertices = image->toArray();
  }

  if(extension == "ppm") {
    image = new Pixmap2(argv[1]);
    width = image->getWidth(), height = image->getHeight(), vertices = image->toArray();
  }

  Surface * view = new Surface("image", width, height);
  view->getRenderer()->add_image(vertices, width, height);
  view->loop();

  delete vertices;
  delete image;

  return 1;
}
