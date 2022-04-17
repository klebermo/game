#ifndef WORLD_H
#define WORLD_H

#include "Shape2d.h"

class Image : public Shape2d {
private:
  float * vertexList;
  int size;
public:
  Image(float * values, int size);
  ~Image();

  void draw();
  
  const GLchar * vertexShaderCode();
  const GLchar * fragmentShaderCode();
};

#endif //WORLD_H
