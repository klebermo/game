#ifndef SURFACE2D_H
#define SURFACE2D_H

#include "Renderer.hpp"

class Surface {
private:
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
