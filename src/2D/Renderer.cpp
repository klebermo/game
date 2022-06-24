#include "Renderer.h"

Renderer::Renderer() {
  //
}

Renderer::~Renderer() {
  //
}

std::vector<Image> Renderer::getImages() {
  return this->images;
}

void Renderer::drawFrame(Display * dpy, Window win, XVisualInfo * vi) {
  GLXContext glc = glXCreateContext(dpy, vi, NULL, GL_TRUE);
  glXMakeCurrent(dpy, win, glc);

  glEnable(GL_DEPTH_TEST); 

  glewExperimental = GL_TRUE;
  glewInit();

  for(int i=0; i<images.size(); i++)
    images[i].init();

  XEvent xev;
  while(1) {
      XNextEvent(dpy, &xev);
      
      if(xev.type == Expose) {
          XWindowAttributes gwa;
          XGetWindowAttributes(dpy, win, &gwa);
          glViewport(0, 0, gwa.width, gwa.height);
          for(int i=0; i<images.size(); i++)
            images[i].draw();
          glXSwapBuffers(dpy, win);
      }
      else if(xev.type == KeyPress) {
          glXMakeCurrent(dpy, None, NULL);
          glXDestroyContext(dpy, glc);
          XDestroyWindow(dpy, win);
          XCloseDisplay(dpy);
          exit(0);
      }
  }
}
