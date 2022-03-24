#ifndef WORLD_H
#define WORLD_H

#include "Shape.h"

class World : public Shape {
private:
  //
public:
  World();
  ~World();

  void draw();
  vector<float> vertices();
  string vertexShaderCode();
  string fragmentShaderCode();
};

#endif //WORLD_H
