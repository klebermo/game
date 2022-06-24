#include "Surface.h"

Surface::Surface(string windows_title, int width, int height) {
  this->width = width;
  this->height = height;
  this->renderer = new Renderer();

  display = XOpenDisplay(NULL);
	if (display == NULL) {
		cout << "Could not open display" << endl;
		exit(1);
	}
	screen = DefaultScreenOfDisplay(display);
	screenId = DefaultScreen(display);

	// Open the window
	window = XCreateSimpleWindow(display, RootWindowOfScreen(screen), 0, 0, 640, 480, 1, BlackPixel(display, screenId), WhitePixel(display, screenId));
}

Surface::~Surface() {
	XDestroyWindow(display, window);
	XFree(screen);
	XCloseDisplay(display);
  delete renderer;
}

void Surface::loop() {
  this->renderer->drawFrame(display, window);
}

Renderer * Surface::getRenderer() {
  return this->renderer;
}
