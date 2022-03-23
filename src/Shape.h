#ifndef SHAPE_H
#define SHAPE_H

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

class Shape {
protected:
  //
public:
  Shape();
  ~Shape();
  virtual void draw() = 0;
};

#endif //SHAPE_H
