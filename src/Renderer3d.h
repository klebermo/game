#ifndef RENDERER3D_H
#define RENDERER3D_H

#include "Renderer.h"

class Renderer3d : public Renderer {
private:
  //
public:
  Renderer3d();
  ~Renderer3d();

  void drawFrame(SDL_Window * window, int width, int height, float * vertices);
};

#endif //RENDERER3D_H
