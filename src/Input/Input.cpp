#include "Input.hpp"

bool Input::pollEvent() {
  return SDL_PollEvent(&windowEvent);
}

SDL_Event Input::getEvent() {
  return this->windowEvent;
}
