#include "Renderer.h"

Renderer::Renderer() {
  //
}

Renderer::~Renderer() {
  //
}

World * Renderer::getWorld() {
  return this->world;
}

void Renderer::setWorld(World * value) {
  this->world = value;
}

vector<shared_ptr<Shape>> Renderer::getShapes() {
  return this->shapes;
}

void Renderer::setShapes(vector<shared_ptr<Shape>> values) {
  this->shapes = values;
}

Input Renderer::getInput() {
  return this->input;
}

void Renderer::setInput(Input value) {
  this->input = input;
}
