#ifndef WORLD_H
#define WORLD_H

#include "Shape.h"

#include "netpbm.h"

class World : public Shape {
private:
  vector<float> vertexList;
public:
  World();
  ~World();

  vector<float> getVertexList();
  void setVertexList(float * values, int size);

  void init();
  void draw();
  const GLchar * vertexShaderCode();
  const GLchar * fragmentShaderCode();
};

#endif //WORLD_H
