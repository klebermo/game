#ifndef RENDERER_H
#define RENDERER_H

#include "World.h"
#include "Shape.h"
#include "Input.h"

#include <iostream>
using namespace std;

#include <string>
using namespace std;

#include <vector>
using namespace std;

class Renderer {
protected:
  World world;
  Shape* shapes;
  Input * input;
public:
  Renderer();
  ~Renderer();
  void drawFrame();
  void surfaceChanged(int width, int height);
};

#endif //RENDERER_H
