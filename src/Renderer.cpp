#include "Renderer.h"

Renderer::Renderer() {
  //
}

Renderer::~Renderer() {
  //
}

Image * Renderer::getImage() {
  return this->image;
}

void Renderer::setImage(Image * value) {
  this->image = value;
}

Input Renderer::getInput() {
  return this->input;
}

void Renderer::setInput(Input value) {
  this->input = input;
}
