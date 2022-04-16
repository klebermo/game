#ifndef RENDERER_H
#define RENDERER_H

#include "Image.h"
#include "Input.h"

class Renderer {
protected:
  Image * image;
  vector<shared_ptr<Shape2d>> shapes;
  Input input;
public:
  Renderer();
  ~Renderer();

  Image * getImage();
  void setImage(Image * image);

  vector<shared_ptr<Shape2d>> getShapes();
  void setShapes(vector<shared_ptr<Shape2d>> values);

  Input getInput();
  void setInput(Input value);

  virtual void drawFrame(SDL_Window * window, int width, int height, float * vertices) = 0;
};

#endif //RENDERER_H
