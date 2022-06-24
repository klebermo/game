#include "Surface.h"

Surface::Surface(std::string windows_title, int width, int height) {
  	this->renderer = new Renderer();

    dpy = XOpenDisplay(NULL);

    if(dpy == NULL) {
    printf("\n\tcannot connect to X server\n\n");
        exit(0);
    }
        
    root = DefaultRootWindow(dpy);

    vi = glXChooseVisual(dpy, 0, att);

    if(vi == NULL) {
        printf("\n\tno appropriate visual found\n\n");
        exit(0);
    } 
    else {
        printf("\n\tvisual %p selected\n", (void *)vi->visualid); /* %p creates hexadecimal output like in glxinfo */
    }


    cmap = XCreateColormap(dpy, root, vi->visual, AllocNone);

    swa.colormap = cmap;
    swa.event_mask = ExposureMask | KeyPressMask;

    win = XCreateWindow(dpy, root, 0, 0, width, height, 0, vi->depth, InputOutput, vi->visual, CWColormap | CWEventMask, &swa);

    XMapWindow(dpy, win);
    XStoreName(dpy, win, windows_title.c_str());
}

Surface::~Surface() {
  delete renderer;
}

Renderer * Surface::getRenderer() {
  return this->renderer;
}

void Surface::loop() {
  this->renderer->drawFrame(dpy, win, vi);
}
