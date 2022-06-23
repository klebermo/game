#ifndef SURFACE3D_H
#define SURFACE3D_H

#include "Renderer.h"

class Surface {
private:
  SDL_Window* window;
  int width;
  int height;
  Renderer * renderer;
public:
  Surface(string windows_title, int width, int height);
  ~Surface();

  void loop();
};

#endif //SURFACE3D_H
