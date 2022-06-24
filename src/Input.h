#ifndef INPUT_H
#define INPUT_H

#include <X11/Xlib.h>
#include <X11/keysym.h>

#include <iostream>
using namespace std;

#include <string>
using namespace std;

#include <vector>
using namespace std;

#include <memory>
using namespace std;

class Input {
private:
  XEvent windowEvent;
public:
  Input();
  ~Input();

  bool pollEvent(Display * display);
  XEvent getEvent();
};

#endif //INPUT_H
