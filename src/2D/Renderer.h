#ifndef RENDERER2D_H
#define RENDERER2D_H

#include "Image.h"

class Renderer {
private:
    std::vector<Image> images;
public:
    Renderer();
    ~Renderer();

    std::vector<Image> getImages();

    void drawFrame(Display * dpy, Window win, XVisualInfo * vi);
};

#endif
