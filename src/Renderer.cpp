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

vector<shared_ptr<Shape2d>> Renderer::getShapes() {
  return this->shapes;
}

void Renderer::setShapes(vector<shared_ptr<Shape2d>> values) {
  this->shapes = values;
}

Input Renderer::getInput() {
  return this->input;
}

void Renderer::setInput(Input value) {
  this->input = input;
}
