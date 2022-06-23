#ifndef SURFACE2D_H
#define SURFACE2D_H

#include "Renderer.h"

class Surface {
private:
  SDL_Window* window;
  int width;
  int height;
  Renderer * renderer;
public:
  Surface(string windows_title, int width, int height, float * vertices);
  ~Surface();

  void loop();
};

#endif //SURFACE2D_H
