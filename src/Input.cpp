#include "Input.h"

Input::Input() {
  //
}

Input::~Input() {
  //
}

bool Input::pollEvent(Display * display) {
  return XNextEvent(display, &windowEvent);
}

XEvent Input::getEvent() {
  return this->windowEvent;
}
