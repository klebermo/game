#ifndef INPUT_H
#define INPUT_H

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <iostream>
using namespace std;

#include <string>
using namespace std;

#include <vector>
using namespace std;

#include <memory>
using namespace std;

class Input {
private:
  SDL_Event windowEvent;
public:
  Input();
  ~Input();

  bool pollEvent();
  SDL_Event getEvent();
};

#endif //INPUT_H
