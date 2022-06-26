#ifndef SURFACE2D_H
#define SURFACE2D_H

#include "Renderer.h"

class Surface {
private:
    SDL_Window* window;
    int width;
    int height;
    Renderer * renderer;
public:
    Surface(std::string windows_title, int width, int height);
    ~Surface();

    Renderer * getRenderer();

    void loop();
};

#endif
