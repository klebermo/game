#ifndef RENDERER2D_H
#define RENDERER2D_H

#include "Renderer.h"

class Renderer2d : public Renderer {
private:
  //
public:
  Renderer2d();
  ~Renderer2d();

  void drawFrame(SDL_Window * window);
};

#endif //RENDERER2D_H
