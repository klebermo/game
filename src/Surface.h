#ifndef SURFACE_H
#define SURFACE_H

#include "Renderer.h"

class Surface {
protected:
  SDL_Window* window;
  int width;
  int height;
  Renderer* renderer;
public:
  Surface(string windows_title, int width, int height);
  ~Surface();

  Renderer * getRenderer();
  void setRenderer(Renderer * value);

  virtual void loop() = 0;
};

#endif //SURFACE_H
