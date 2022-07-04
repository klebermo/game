#ifndef RENDERER2D_H
#define RENDERER2D_H

#include "Image.h"
#include "../Input/Input.h"

class Renderer {
private:
    //std::vector<Image> images;
    Image * image;
    Input input;
public:
    Renderer();
    ~Renderer();

    //std::vector<Image> getImages();
    void setImage(Image * image);

    void drawFrame(SDL_Window * window);
};

#endif
