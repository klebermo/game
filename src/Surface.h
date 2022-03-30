#ifndef SURFACE_H
#define SURFACE_H

#include "Renderer.h"

class Surface {
protected:
  SDL_Window* window;
  int width;
  int height;
  Renderer* renderer;
  float* vertices;
public:
  Surface(string windows_title, int width, int height);
  ~Surface();

  Renderer * getRenderer();
  void setRenderer(Renderer * value);

  float * getVertices();
  void setVertices(float * values);

  virtual void loop() = 0;
};

#endif //SURFACE_H
