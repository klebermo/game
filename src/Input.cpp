#include "Input.h"

Input::Input() {
  //
}

Input::~Input() {
  //
}

bool Input::pollEvent() {
  return SDL_PollEvent(&windowEvent);
}

SDL_Event Input::getEvent() {
  return this->windowEvent;
}
