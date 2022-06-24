#ifndef SURFACE2D_H
#define SURFACE2D_H

#include "Renderer.h"

class Surface {
private:
  Display * display;
	Screen * screen;
	int screenId;
  Window window;

  int width;
  int height;
  Renderer * renderer;
public:
  Surface(string windows_title, int width, int height);
  ~Surface();

  Renderer * getRenderer();

  void loop();
};

#endif
