#ifndef RENDERER3D_H
#define RENDERER3D_H

#include "../Input.h"

class Renderer {
private:
  Input input;
public:
  Renderer();
  ~Renderer();

  void drawFrame(SDL_Window * window);
};

#endif //RENDERER3D_H
