#ifndef SURFACE2D_H
#define SURFACE2D_H

#include "Renderer.h"

class Surface {
private:
    Display                 *dpy;
    Window                  root;
    GLint                   att[5] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
    XVisualInfo             *vi;
    Colormap                cmap;
    XSetWindowAttributes    swa;
    Window                  win;

    Renderer * renderer;
public:
    Surface(std::string windows_title, int width, int height);
    ~Surface();

    Renderer * getRenderer();

    void loop();
};

#endif
