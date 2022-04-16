#ifndef WORLD_H
#define WORLD_H

#include "Shape2d.h"

#include "netpbm.h"

class Image : public Shape2d {
private:
  vector<float> vertexList;
public:
  Image();
  ~Image();

  vector<float> getVertexList();
  void setVertexList(float * values, int size);

  void init();
  void draw();
  const GLchar * vertexShaderCode();
  const GLchar * fragmentShaderCode();
};

#endif //WORLD_H
