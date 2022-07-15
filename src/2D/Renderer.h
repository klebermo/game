#ifndef RENDERER2D_H
#define RENDERER2D_H

#include "Image.h"
#include "Animation.h"
#include "../Input/Input.h"

class Renderer {
private:
    Image * image;
    Input input;
public:
    Renderer();
    ~Renderer();
    void setImage(float * vertices, int width, int height);
    void drawFrame(SDL_Window * window);
    void showAnimation(SDL_Window * window);
};

#endif
