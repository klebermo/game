#ifndef RENDERER3D_H
#define RENDERER3D_H

#include "Shape.hpp"
#include "../Input/Input.hpp"

class Renderer {
private:
  Input input;
public:
  Renderer();
  ~Renderer();

  void drawFrame();
};

#endif //RENDERER3D_H
