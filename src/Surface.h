#ifndef SURFACE_H
#define SURFACE_H

#include "Renderer.h"

class Surface {
protected:
  SDL_Window* window;
	SDL_Surface* surface;
  SDL_GLContext context;
  Renderer renderer;
public:
  Surface();
  Surface(string windows_title);
  ~Surface();

  void loop();

  Renderer getRenderer();
  void setRenderer(Renderer renderer);
};

#endif //SURFACE_H
