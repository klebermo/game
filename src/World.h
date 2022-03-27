#ifndef WORLD_H
#define WORLD_H

#include "Shape.h"

#include "netpbm.h"

class World : public Shape {
private:
  vector<float> vertexList;
public:
  World(GLfloat * vertices);
  ~World();

  void draw();
  vector<float> vertices();
  string vertexShaderCode();
  string fragmentShaderCode();
};

#endif //WORLD_H
