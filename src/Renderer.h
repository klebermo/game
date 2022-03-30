#ifndef RENDERER_H
#define RENDERER_H

#include "World.h"
#include "Input.h"

class Renderer {
protected:
  World * world;
  vector<shared_ptr<Shape>> shapes;
  Input input;
public:
  Renderer();
  ~Renderer();

  World * getWorld();
  void setWorld(World * world);

  vector<shared_ptr<Shape>> getShapes();
  void setShapes(vector<shared_ptr<Shape>> values);

  Input getInput();
  void setInput(Input value);

  virtual void drawFrame(SDL_Window * window, int width, int height, float * vertices) = 0;
};

#endif //RENDERER_H
