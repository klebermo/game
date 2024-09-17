#ifndef RENDERER2D_H
#define RENDERER2D_H

#include "Image.hpp"
#include "../Input/Input.hpp"

class Renderer {
private:
    Image * image;
    Input input;
public:
    Renderer();
    ~Renderer();

    void setImage(float * vertices, int width, int height);
    void drawFrame();
};

#endif
