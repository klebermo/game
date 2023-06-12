#ifndef SURFACE2D_H
#define SURFACE2D_H

#include "Renderer.hpp"

class Surface {
private:
    SDL_Window* window;
    int width;
    int height;
public:
    Surface(std::string windows_title, int width, int height);
    ~Surface();

    void loop();
};

#endif
