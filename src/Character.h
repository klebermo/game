#ifndef CHARACTER_H
#define CHARACTER_H

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

class Character {
protected:
  //
public:
  Character();
  ~Character();
  virtual void draw() = 0;
};

#endif //CHARACTER_H
