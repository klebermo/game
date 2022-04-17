#ifndef RENDERER_H
#define RENDERER_H

#include "Image.h"
#include "Input.h"

class Renderer {
protected:
  Image * image;
  Input input;
public:
  Renderer();
  ~Renderer();

  Image * getImage();
  void setImage(Image * image);

  Input getInput();
  void setInput(Input value);

  virtual void drawFrame(SDL_Window * window, int width, int height, float * vertices) = 0;
};

#endif //RENDERER_H
