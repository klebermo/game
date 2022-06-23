#ifndef RENDERER2D_H
#define RENDERER2D_H

#include "Image.h"
#include "../Input.h"

class Renderer {
private:
  Image * image;
  Input input;
public:
  Renderer(Image * image);
  ~Renderer();

  void drawFrame(SDL_Window * window);
};

#endif //RENDERER2D_H
