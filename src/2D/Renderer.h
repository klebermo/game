#ifndef RENDERER2D_H
#define RENDERER2D_H

#include "Image.h"
#include "../Input.h"

#include <vector>

class Renderer {
private:
  std::vector<Image *> images;
  Input input;
public:
  Renderer();
  ~Renderer();

  void add_image(Image * image);
  void add_image(float * vertices, int width, int height);
  void drawFrame(Display * display, Window window);
};

#endif
