#ifndef RENDERER_H
#define RENDERER_H

#include "World.h"
#include "Shape.h"
#include "Input.h"

class Renderer {
protected:
  World * world;
  vector<shared_ptr<Shape>> shapes;
  Input input;
public:
  Renderer();
  ~Renderer();

  virtual void drawFrame(SDL_Window * window) = 0;
};

#endif //RENDERER_H
