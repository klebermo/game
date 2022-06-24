#include "Renderer.h"

Renderer::Renderer() {
  //
}

Renderer::~Renderer() {
  //
}

void Renderer::add_image(Image * image) {
  images.push_back(image);
}

void Renderer::add_image(float * vertices, int width, int height) {
  std::cout << "add_image: " << width << "x" << height << std::endl;
  Image * image = new Image(vertices, width, height);
  std:cout << "image: " << image << std::endl;
  images.push_back(image);
  std::cout << "images: " << images.size() << std::endl;
}

void Renderer::drawFrame(Display * display, Window window) {
  KeySym escape = XKeysymToKeycode(display, XK_Escape);

  glewExperimental = GL_TRUE;
  glewInit();

  while(true) {
    if(input.pollEvent(display)) {
      if (input.getEvent().type == KeyRelease && input.getEvent().xkey.keycode == escape) break;
    }

    for(int i=0; i<images.size(); i++) {
      images[i]->draw();
    }
  }
}
