#ifndef SURFACE_H
#define SURFACE_H

#include "Renderer.h"

class Surface {
protected:
  SDL_Window* window;
  int width;
  int height;
public:
  Surface(string windows_title, int width, int height);
  ~Surface();

  virtual void loop(float * array) = 0;
};

#endif //SURFACE_H
